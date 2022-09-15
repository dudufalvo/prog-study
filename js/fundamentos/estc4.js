// loop 2

for(let i=1; i<=10; i++) {
    console.log(`counter2 = ${i}`)
}

const grades = [5, 12, 4, 2, 8, 3, 10]
for(let j=0; j<grades.length; j++) {
    console.log(`grade${j+1} = ${grades[j]}`)
}

for (grade in grades) {
    console.log(`grade${grade} = ${grades[grade]}`)
}

const person = {
    name: 'eduardo',
    last_name: 'falvo',
    age: 23,
    weight: 70
}

for (atributes in person) {
    console.log(`${atributes} = ${person[atributes]}`)
}