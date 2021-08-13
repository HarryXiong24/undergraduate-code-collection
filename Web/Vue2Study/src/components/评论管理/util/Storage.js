const KEY_NAME = 'key'
export default {
  saveData (value) {
    window.localStorage.setItem(KEY_NAME, JSON.stringify(value))
  },
  getData () {
    return JSON.parse(window.localStorage.getItem(KEY_NAME) || "[]") 
  }
}