const readline = require("readline");

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
            r1.question("Enter Task: ", task => {
                tasks.push({text : task, done : false});
                console.log("Task Added.");
                displayMenu();
            });
            break;
        case "2":
            console.log("-------- Task List ---------");
            tasks.forEach((t, i) =>
            console.log(`${i}. [${t.done ? "DONE" : "NOT DONE"}] ${t.text}`));
            displayMenu();
            break;
        case "3":
            r1.question("Enter task id: ", n => {
                if (tasks[n]) {
                    tasks[n].done = true;
                    console.log("Marked Done");
                }
                displayMenu();
            });
            break;
        case "4":
            r1.question("Enter task id: ", n => {
                tasks.splice(n, 1);
                console.log("Deleted Task");
                displayMenu();
            });
            break;
        case "5":
            r1.close();
            break;
        default:
            displayMenu();
    }
}

displayMenu();