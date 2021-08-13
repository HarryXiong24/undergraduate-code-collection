export default {
  completed: function (state) {
    let sum = 0
    for (let i = 0; i < state.items.length; i++) {
      if (state.items[i].complete === true) {
        sum = sum + 1
      }
    }
    return sum
  },
  toCheck: function (getters) {
    return getters.completed === getters.items.length && getters.completed > 0
  }
}
