/* arrays */

const array = [2.4, 4.5, 98, 10];
console.log(array[0]);
console.log(array[4]); // there is no index 4 - undefined

array[4] = 23;
console.log(array[4]); // now there is a index 4
console.log(array);

array.push(40);
console.log(array);

array.pop();
console.log(array);

delete array[3];
console.log(array);

console.log(typeof array);