// let mynums=[1,2,3,4,5,6,7,8,9];

// const nums=mynums.filter((num)=>{   //filter
//   return num>4
// })
// console.log(nums);


// const newnums=[]                    //forEach
// mynums.forEach((num)=>{
//   if(num>4){
//     newnums.push(num)
//   }
// })
// console.log(newnums)
 

// const mapnums=mynums.map((num)=>{     //map and chaining
//   return num+10
// }).filter((num)=>{
//   return num>15
// })
// console.log(mapnums)


// const val=mynums.reduce((accumulator,currval)=>{  //reduce take two parameters one callback and other a initial value
//   return accumulator+currval                      //that will be initially taken for operations performed in call back
// },0)
// console.log(val);


// const promisify=new Promise((resolve,reject)=>{
//   setTimeout(()=>{
//     const done=true;
//     if(done){
//       resolve("promise is fulfilled !")
//     }
//     else{
//       reject("the promise is not fulfilled !")
//     }
    
//   },1000)
// })

// async function callpromise(){
//   try{

//     const response=await promisify;
//     console.log(response)
//   }
//   catch(error){
//     console.log(error)
//   }
// }

// callpromise()


// async function getusers(){
//   try{
//     const response=await fetch("https://jsonplaceholder.typcode.com/users")
//     const data=await response.json()
//     console.log(data);

//   }
//   catch(error){
//     console.log(`Error is ${error}`)
//   }
  

// }


// getusers()

//sort function
//callback hell and promises revision
//typescript
//react basics and hooks like custom hooks and inbuilt ones(all)



function do1(){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      console.log("task1 complete !")
      resolve("Came from task one !")
    },1000);
  })
  
}


function do2(){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      console.log("task2 complete !")
      resolve("Came from task 2 !")
    },1000);
  })
  
}



function do3(){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      console.log("task3 incomplete !")
      reject("Rejected task 3 !")
    },1000);
  })
  
}



function do4(){
  return new Promise((resolve,reject)=>{
    setTimeout(()=>{
      console.log("task4 complete !")
      resolve("Came from task 4 !")
    },1000);
  })
  
}

//USING CALLBACKS 

// do1(()=>{
//   do2(()=>{
//     do3(()=>{
//       do4(()=>{
//         console.log("All tasks complete !!")
//       })
//     })
//   })
// })


//USING PROMISES 

// do1()    
//   .then((msg) => {
//     console.log(msg);
//     return do2();
//   })
//   .then((msg) => {
//     console.log(msg);
//     return do3();
//   })
//   .then((msg) => {
//     console.log(msg);
//     return do4();
//   })
//   .then((msg) => {
//     console.log(msg);
//     console.log("All tasks complete !");
//   })
//   .catch((err) => {
//     console.log(err);
//   });

//USING PROMISES AND ASYNC AWAIT

async function executeTasks() {
  try {
    let msg = await do1();
    console.log(msg);

    msg = await do2();
    console.log(msg);

    msg = await do3();
    console.log(msg);

    msg = await do4();
    console.log(msg);

    console.log("All tasks complete !");
  } catch (err) {
    console.log(err);
  }
}

executeTasks()





