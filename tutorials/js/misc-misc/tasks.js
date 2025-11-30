const readline = require("readline");
const { text } = require("stream/consumers");

const r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let tasks = [];

function displayMenu(){
    console.log(`
------- Task List -------
1. Add Task
2. List Tasks
3. Mark Complete
4. Delete Task
5. Exit        
`);
r1.question("Choose Option: ", handleRequest);
}

function handleRequest(option){
    switch (option){
        case "1":
            r1.question("Enter Question: ", task => {
                tasks.push({text : task, done : false});
                console.log("Task Added.");
                displayMenu();
            });
            break;
    }
}