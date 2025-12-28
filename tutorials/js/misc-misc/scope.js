// var is function scopes and let/const are block scoped

function scope()
{
    if (true){
        // block 
        var a = 1;
        var b = 2;
        const c = 3;      // block scoped    
        let d = "batman"; // block scoped
    }

    console.log(a);
    console.log(b);
    console.log(c); 
    console.log(d);
}

scope()

