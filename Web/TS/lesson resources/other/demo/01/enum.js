var Color;
(function (Color) {
    Color[Color["Red"] = 0] = "Red";
    Color[Color["Green"] = 1] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
})(Color || (Color = {}));
;
var a1 = Color.Green;
var a2 = Color[2];
if (true)
    console.log(a1);
if (true)
    console.log(a2);
