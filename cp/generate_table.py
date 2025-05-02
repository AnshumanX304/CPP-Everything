import random
import string
import uuid
import psycopg2
from sqlalchemy import (
    create_engine, MetaData, Table, Column,
    Integer, Float, Boolean, String, Text,
    Date, DateTime, Time, JSON
)
from sqlalchemy.dialects.postgresql import UUID
from sqlalchemy.engine.url import URL
from datetime import datetime

# --- Config ---
DB_NAME = ""
DB_USER = ""
DB_PASSWORD = ""
DB_HOST = ""
DB_PORT = ""

NUM_TABLES = 200
MIN_COLS = 300
MAX_COLS = 400

# --- Helpers ---
def random_name(prefix, length=8):
    return prefix + ''.join(random.choices(string.ascii_lowercase, k=length))

sql_types = [Integer, Float, Boolean, String(100), Text, Date, DateTime, Time, JSON, UUID]

# --- Ensure Database Exists ---
def ensure_database_exists():
    try:
        conn = psycopg2.connect(
            dbname="postgres",
            user=DB_USER,
            password=DB_PASSWORD,
            host=DB_HOST,
            port=DB_PORT
        )
        conn.autocommit = True
        cursor = conn.cursor()
        cursor.execute(f"SELECT 1 FROM pg_database WHERE datname = %s;", (DB_NAME,))
        exists = cursor.fetchone()
        if not exists:
            cursor.execute(f'CREATE DATABASE "{DB_NAME}";')
            print(f"📀 Created database: {DB_NAME}")
        else:
            print(f"✔️ Database '{DB_NAME}' already exists.")
        cursor.close()
        conn.close()
    except Exception as e:
        print("❌ Error ensuring database exists:", e)
        exit(1)

# --- Create Tables ---
def create_tables():
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

    with engine.begin() as conn:
        for i in range(NUM_TABLES):
            table_name = f"tbl_{i+1:03d}_{random_name('', 5)}"
            num_cols = random.randint(MIN_COLS, MAX_COLS)

            columns = [Column("id", Integer, primary_key=True)]
            for j in range(num_cols):
                col_type = random.choice(sql_types)
                col_name = f"col_{j+1:03d}_{random_name('', 3)}"
                columns.append(Column(col_name, col_type))

            Table(table_name, metadata, *columns)
            print(f"🧱 Prepared: {table_name} with {len(columns)} columns")

        metadata.create_all(engine)
        print("✅ All tables created successfully.")

# --- Main ---
if __name__ == "__main__":
    ensure_database_exists()
    create_tables()
