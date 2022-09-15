// functions 2

// variable parameters with 'arguments'
const sumNumbers = () => {
    let sum = 0
    for (index in arguments) {
        sum += arguments[index]
    }
    return sum
}

console.log(sumNumbers())
console.log(sumNumbers(1, 2))
console.log(sumNumbers(1, 2, 3))
console.log(sumNumbers(1, 2, 3, 'a'))

// standard value for parameter
const subNumbers = (a, b, c) => {
    a = a || 1
    b = b || 2
    c = c || 3
    return a - b - c
}

const mulNumbers = (a, b, c) => {
    a = a !== undefined ? a : 1
    b = 1 in arguments ? b : 2
    c = isNaN(c) ? 3 : c
    return a * b * c
}

const divNumbers = (a=1, b=2, c=3) => {
    return a/b/c
}