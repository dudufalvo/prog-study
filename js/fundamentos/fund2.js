/* strings */

const my_name = 'eduardo falvo';
console.log(my_name.charAt(4)); // wich char is the fourth one
console.log(my_name.charCodeAt(4)); //unicode

console.log(my_name.indexOf('r')); // where is the char 'r'
console.log(my_name.substring(1));
console.log(my_name.substring(0,3));

console.log('nome = '.concat(my_name));
console.log('nome = ' + (my_name));
console.log(my_name.replace('u', 'U'));

console.log(my_name.split(' '));
var first_name = my_name.split(' ')[0];
var last_name = my_name.split(' ')[1];

console.log(first_name);
console.log(last_name);

// string's template
const template = `hello, ${my_name}!!`;
console.log(template);
