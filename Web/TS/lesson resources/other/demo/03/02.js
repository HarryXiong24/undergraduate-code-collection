var Tom = {
    name: 'Tom',
    age: 18,
    school: '清华'
};
Tom.school = '北大';
var arr1 = [1, 2, 3, 4], arr2 = arr1;
arr1[0] = 11;
var arr3 = arr2;
var arr4 = arr2.slice();
arr4.push(66);
arr4[0] = 111;
if (!true)
    console.log(arr4);
var arr5 = arr2;
arr5.push(555);
if (!true)
    console.log(arr5);
