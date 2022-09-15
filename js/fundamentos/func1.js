// functions

// literal function
function func1() { }

// function stored inside a variable
const func2 = function () { }

// function stored inside an array
const array = [function(a, b) { return a + b}, func1, func2]
console.log(array[0](2, 3))

// function stored inside a object as it's attribute 
const object = { }
object.speak = function () { return 'hey' }
console.log(object.speak)

// function as parameter
function run(fun) {
    fun()
}
run(function () { console.log('exec...') })

// function return/containing another function
function sum(a, b) {
    return function (c) {
        console.log(a + b + c)
    }
}
sum(1, 2)(3)
