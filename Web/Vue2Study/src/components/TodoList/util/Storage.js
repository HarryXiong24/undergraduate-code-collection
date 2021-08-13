const KEY_NAME = 'item_key'
export default {
  savaData (value) {
    window.localStorage.setItem(KEY_NAME, JSON.stringify(value))
  },
  getData () {
    return JSON.parse(window.localStorage.getItem(KEY_NAME) || '[]')
  }
}
