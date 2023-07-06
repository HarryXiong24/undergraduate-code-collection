package main

import (
	"net/http"
	"time"
)

func main() {
	//startDefaultServer()

	//startMyServer()

	multiHandlerServer()

	//http.ListenAndServe(":8080", http.FileServer(http.Dir("wwwroot")))
}

func startDefaultServer() {
	//第一个参数：路由地址
	//第二个参数：处理请求的函数
	http.HandleFunc("/",
		func(writer http.ResponseWriter, r *http.Request) {
			writer.Write([]byte("hello world"))
		})

	//开启http请求监听
	//参数1 ：地址，默认为 *:80
	//参数2 ：handler，默认是 DefaultServeMux，是一个multiplexer（看成路由器）
	http.ListenAndServe("localhost:8080", nil)
}

func startMyServer() {
	//自定义server
	server := http.Server{
		Addr:    "localhost: 8080",
		Handler: myHandler{}, //不指定，默认为 DefaultServeMux
	}

	server.ListenAndServe()
}

// 自定义 Handler
type myHandler struct{}

// myHandler 实现 Handler 接口
// 接收请求，返回"Hello gopher"字符串
func (h myHandler) ServeHTTP(rw http.ResponseWriter, r *http.Request) {
	rw.Write([]byte("Hello gopher"))
}

func multiHandlerServer() {
	server := http.Server{
		Addr:    "localhost: 8080",
		Handler: nil, //此时为 DefaultServeMux
	}
	http.Handle("/", indexHandler{})
	http.Handle("/a", aHandler{})
	http.Handle("/b", bHandler{})

	//******* 几个内置的 handler ********
	//404
	http.Handle("/nowhere", http.NotFoundHandler())
	//超时
	http.Handle("/timeout", http.TimeoutHandler(http.HandlerFunc(func(rw http.ResponseWriter, r *http.Request) {
		time.Sleep(3 * time.Second)
	}), 1*time.Second, "time out!!!"))
	//跳转
	http.Handle("/redirect", http.RedirectHandler("b", http.StatusSeeOther))

	//文件服务器
	//http.Handle("/files/", http.StripPrefix("/files", myFileServer{}))
	http.Handle("/files/", http.StripPrefix("/files", http.FileServer(http.Dir("wwwroot"))))

	server.ListenAndServe()
}

type indexHandler struct{}

func (ih indexHandler) ServeHTTP(rw http.ResponseWriter, r *http.Request) {
	rw.Write([]byte("Hello gopher"))
}

type aHandler struct{}

func (ah aHandler) ServeHTTP(rw http.ResponseWriter, r *http.Request) {
	rw.Write([]byte("Hello gopher from aHandler"))
}

type bHandler struct{}

func (bh bHandler) ServeHTTP(rw http.ResponseWriter, r *http.Request) {
	rw.Write([]byte("Hello gopher from bHandler"))
}

type myFileServer struct{}

func (mfs myFileServer) ServeHTTP(rw http.ResponseWriter, r *http.Request) {
	http.ServeFile(rw, r, "wwwroot"+r.URL.Path)
}
