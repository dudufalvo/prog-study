/* functions */

function printSum(a, b) {
    console.log(a+b);
}

printSum(3,4);
printSum(3);            // returns not a number
printSum(3,4,5,6,7);    // uses the first two ones and ignore the others

function sum(a, b=0) {
    return a+b;
}
console.log(sum(3,4));
console.log(sum(3));

// storing a function into a variabel
const printSub = function (a, b) {
    console.log(a-b);
}
printSub(3,2);

// using arrow function
const sub = (a, b) => {
    return a-b;
}
console.log(sub(4,2));
