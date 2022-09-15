/* operators */

// destructuring
const person = {
    fname: 'ana',
    age: 20,
}

const { fname, age } = person;
console.log(fname, age);

const { fname: n, age: a } = person;
console.log(n, a);

const { lname, isOnline=true} = person;
console.log(lname, isOnline);


function rand({min = 0, max = 1000}) {
    const value = Math.random() * (max-min) + min;
    return Math.floor(value);
}

const object = {min: 40, max: 50};
console.log(rand(object));

function rand2([min = 0, max = 1000]) {
    if(min > max) [min, max] = [max, min];
    const value = Math.random() * (max-min) + min;
    return Math.floor(value);
}

console.log(rand2([50, 40]));

// ternary
const result = (rate) => { 
    return rate >= 7 ? 'approved':'not approved';
    //if (rate >= 7) return 'approved';
    //else return 'not approved';
}
console.log(result(7.1));
console.log(result(6.7));