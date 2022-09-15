/*  variables - constants - numbers */
var num1 = 3;
let num2 = 4;

var num1 = 10;
//let num2 = 20; - redeclaration error

num1 = num1 + 1;
num2 = num2 + 1;

console.log(num1);
console.log(num2);

const num3 = 20;
//num3 = 30; - error const being changed
console.log(num3);

let str1 = 'string';
console.log(str1);
console.log(typeof str1);
console.log(typeof num1);

const num4 = Number('4.5');
console.log(num4);
console.log(typeof num4);
console.log(Number.isInteger(num4));
console.log(num4.toFixed(1));
console.log(num4.toString());

console.log("10"/2);
console.log("10a.2"/2); // error - not a number