// conditions

function gradeApproval(grade) {
    if (grade >= 7) console.log("you have passed with a "+grade+" grade");
    else console.log("you've failed")
}

gradeApproval(7);

function itsTrue(bool) {
    if (bool) console.log("that's true");
    else console.log("that's not true");
}

itsTrue();
itsTrue(null);
itsTrue(undefined);
itsTrue(NaN);
itsTrue('');
itsTrue(0);
itsTrue(1);
itsTrue(' ');
itsTrue('?');
itsTrue([]);
itsTrue([1, 2, 3]);
itsTrue({});