import random
import string
import uuid
import json
from datetime import datetime, date, time
from sqlalchemy import create_engine, MetaData, Table
from sqlalchemy.engine.url import URL
from sqlalchemy.dialects.postgresql import UUID as PG_UUID
from sqlalchemy.types import (
    Integer, Float, Boolean, String, Text, Date, DateTime, Time, JSON as JSONType
)

# --- Config ---
DB_NAME =""
DB_USER =""
DB_PASSWORD =""
DB_HOST =""
DB_PORT =""

BATCH_SIZE = 500  # rows per insert batch
MIN_ROWS = 1000
MAX_ROWS = 10000

# --- Setup ---
db_url = URL.create(
    drivername="postgresql",
    username=DB_USER,
    password=DB_PASSWORD,
    host=DB_HOST,
    port=DB_PORT,
    database=DB_NAME
)
engine = create_engine(db_url)
metadata = MetaData()

# --- Data Generators ---
def gen_value(col_type):
    if isinstance(col_type, Integer):
        return random.randint(1, 100000)
    elif isinstance(col_type, Float):
        return round(random.uniform(1.0, 100000.0), 2)
    elif isinstance(col_type, Boolean):
        return random.choice([True, False])
    elif isinstance(col_type, String) or isinstance(col_type, Text):
        return ''.join(random.choices(string.ascii_letters + string.digits, k=12))
    elif isinstance(col_type, Date):
        return date.today()
    elif isinstance(col_type, DateTime):
        return datetime.utcnow()
    elif isinstance(col_type, Time):
        return datetime.utcnow().time()
    elif isinstance(col_type, JSONType):
        return {"val": random.randint(1, 100)}
    elif isinstance(col_type, PG_UUID):
        return str(uuid.uuid4())
    else:
        return None

# --- Main Logic ---
def populate_tables():
    metadata.reflect(bind=engine)
    with engine.begin() as conn:
        for i, table_name in enumerate(metadata.tables):
            table = Table(table_name, metadata, autoload_with=engine)
            print(f"📥 Populating: {table_name}")

            num_rows = random.randint(MIN_ROWS, MAX_ROWS)
            rows = []
            col_types = {col.name: col.type for col in table.columns if col.name != "id"}

            for row_id in range(1, num_rows + 1):
                row = {"id": row_id}
                for col_name, col_type in col_types.items():
                    row[col_name] = gen_value(col_type)
                rows.append(row)

                # Batch insert
                if len(rows) == BATCH_SIZE:
                    conn.execute(table.insert(), rows)
                    rows = []

            # Insert remaining
            if rows:
                conn.execute(table.insert(), rows)

            print(f"✅ Inserted {num_rows} rows into {table_name}")

    print("🎉 Done populating all tables!")

# --- Entry ---
if __name__ == "__main__":
    populate_tables()
