/**
 * mutations
 */
import {ADD_ITEM, DEL_ITEM, DEL_CHOOSE_ALL, SET_CHOOSE_ALL, UPDATE_ITEMS} from './mutation-types'

export default {
  [ADD_ITEM] (state, newItem) {
    state.items.push(newItem)
  },
  [DEL_ITEM] (state, index) {
    state.items.splice(index, 1)
  },
  [DEL_CHOOSE_ALL] (state) {
    state.items = state.items.filter((item) => {
      return item.complete === false
    })
  },
  [SET_CHOOSE_ALL] (state, value) {
    if (value === true) {
      for (let i = 0; i < state.items.length; i++) {
        state.items[i].complete = true
      }
    } else {
      for (let i = 0; i < state.items.length; i++) {
        state.items[i].complete = false
      }
    }
  },
  [UPDATE_ITEMS] (state, date) {
    state.items = date
  }
}
