// switch

const gradeApproval = (grade) => {
    switch (Math.floor(grade)) {
        case 10:
        case 9:
            console.log('honors')
            break
        case 8: case 7:
            console.log('approved')
            break
        case 6: case 5: case 4:
            console.log('wait listed')
            break
        case 3: case 2: case 1:
            console.log('not approved')
            break
        default:
            console.log('invalid grade')
    }
}

gradeApproval(4)