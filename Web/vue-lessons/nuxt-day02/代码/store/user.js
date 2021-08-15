// 存放仓库该分类（user）下的数据, export const state = {}是固定的格式
export const state = {
    // 登录成功后接口返回的用户数据, 里面包含了token和用户的详细信息
    userInfo: {}
};

// 修改state中的数据 export const mutations = {}是固定的格式
// store的数据不能直接修改，必须要使用mutations来修改
export const mutations = {
    // 声明一个函数，函数名可以随便起
    // 该函数有两个参数，第一个参数是上面state(固定的), 第二个参数是传入的参数(不固定)
    setUserInfo(state, data){
        // 随意的修改state的属性
        state.userInfo = data;
        // console.log("store的数据被修改了:", state.userInfo)
    }
}