// loops

const randIntBetween = (min, max) => {
    const value = Math.random() * (max - min) + min
    return Math.floor(value)
}

let number = 0
while (number != -1) {
    number = randIntBetween(-1, 10)
    console.log(`the number is: ${number}`)
}
console.log('the end!')


let number2
do {
    number2 = randIntBetween(5, 15)
    console.log(`the number is: ${number2}`)
} while (number2 != 13)
console.log('the end 2!')


let counter = 1
while(counter <= 10) {
    console.log(`counter = ${counter}`)
    counter++
}