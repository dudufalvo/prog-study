/* loops */

for (var i = 0; i < 10; i++) {
    console.log(i);
}
console.log(i);

for (let j = 0; j < 10; j++) {
    console.log(j);
}
console.log(j);

const funcs = []

for (var k=0; k < 10; k++) {
    funcs.push(function() {
        console.log(k);
    })
}

funcs[2]()
funcs[8]()

const funcs2 = []

for (let l=0; l < 10; l++) {
    funcs2.push(function() {
        console.log(l);
    })
}

funcs2[2]()
funcs2[8]()