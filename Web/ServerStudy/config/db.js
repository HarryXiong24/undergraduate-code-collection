const mongoose = require("mongoose");
// 地址格式 "mongodb://地址:端口号/数据库名"
const db = "mongodb://localhost/test";

exports.db = () => {
  // 连接数据库
  mongoose.connect(db);

  // 设置最大的重连次数
  let maxConnectTimes = 0;

  return new Promise((resolve, reject) => {
    // 增加数据库监听事件
    mongoose.connection.on("disconnected", () => {
      console.log("***********数据库断开***********");
      if (maxConnectTimes <= 3) {
        maxConnectTimes++;
        mongoose.connect(db);
      } else {
        reject();
        throw new Error("数据库出现问题!");
      }
    });

    mongoose.connection.on("error", (err) => {
      console.log("***********数据库错误***********");
      if (maxConnectTimes <= 3) {
        maxConnectTimes++;
        mongoose.connect(db);
      } else {
        reject(err);
        throw new Error("数据库出现问题!.....");
      }
    });

    // 连接成功
    mongoose.connection.once("open", () => {
      console.log("数据库连接成功!");

      resolve();
    });
  });
};
