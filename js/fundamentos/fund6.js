/* variables */
// var - global and funtion scopes
// let - global, block and function scopes

var variable1 = 'test';
{var variable2 = 'test 2';}

console.log(variable1);
console.log(variable2); // visible out of the block

function test() {
    var local = 123;
    console.log(local);
}
//console.log(local); // out of scope

var number = 1;
{
    var number = 2;
    console.log(number);
}
console.log(number);

let number2 = 3;
{
    let number2 = 4;
    console.log(number2);
}
console.log(number2);