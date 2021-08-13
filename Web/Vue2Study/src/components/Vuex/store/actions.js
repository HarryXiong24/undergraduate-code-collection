/**
 * actions
 * 间接调用
 */
import {ADD_ITEM, DEL_CHOOSE_ALL, DEL_ITEM, SET_CHOOSE_ALL, UPDATE_ITEMS} from './mutation-types'
import Storage from '../util/Storage'

export default {
  addItem ({commit}, newItem) {
    commit(ADD_ITEM, newItem)
  },
  delItem ({commit}, index) {
    commit(DEL_ITEM, index)
  },
  delChooseItem ({commit}) {
    commit(DEL_CHOOSE_ALL)
  },
  setChooseAll ({commit}, value) {
    commit(SET_CHOOSE_ALL, value)
  },
  updateItems ({commit}) {
    const date = Storage.getData()
    commit(UPDATE_ITEMS, date)
  }
}
