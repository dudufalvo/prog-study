/* objects */

const objct1 = {};
objct1.first_name = 'eduardo';
objct1.last_name = 'falvo';
objct1.age = 19;
objct1.birthday = '09/04/2003';

console.log(objct1);

const objct2 = {
    first_name: 'eduardo',
    last_name: 'falvo',
    age: 19,
    birthday: '09/04/2003'
}

// both a and b point to the same memory point wich has the object
const a = {name: 'test'};
const b = a;

console.log(b);

b.name = 'another test';
console.log(a);
