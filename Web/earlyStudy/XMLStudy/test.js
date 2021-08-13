var minSubArrayLen = function(s, nums) {
    var sum = 0
    var count = 0
    var min = 1000000
    for (var i = 0; i < nums.length; i++) {
        sum += nums[i]
        count++
        if (sum >= s) {
            if (min >= count) {
                min = count
            }
            count = 0
            sum = 0
        }
    }
    
    console.log(min)
};

minSubArrayLen(7, [0])