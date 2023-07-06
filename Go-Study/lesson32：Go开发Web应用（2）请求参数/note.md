# Go开发Web应用（2）：请求参数
前言：[上一篇文章](https://github.com/Xuhy0826/Go-Go-Study/blob/master/lesson31%EF%BC%9AGo%E5%BC%80%E5%8F%91Web%E5%BA%94%E7%94%A8%E5%85%A5%E9%97%A8%EF%BC%881%EF%BC%89Handler/note.md "上一篇文章")介绍了通过Go如何创建与启动Web服务器，并通过创建`Handler`来处理相应的请求。处理请求的前提是要获取到请求中的数据。`Request`结构中包含了请求报文在经过语法分析后较重要的信息，通过它可以获取到请求中的数据。

## 获取QueryString
查询参数是请求中较常见的参数形式，这种参数是同请求的URL一起发送至服务端，所以获取这种参数也是从请求的URL中获取。`Request`结构已经做好的封装。如请求为：`http://localhost:8080/order?name=xuhy&orderid=123&name=jason`，其中包含三个查询参数，且两个是同名的。如下获取其参数的示例
```go
func main() {
    http.HandleFunc("/order", func(w http.ResponseWriter, r *http.Request){
        query := r.URL.Query()
        
        //获取参数切片：[]string
        name := query["name"]           //[xuhy jason]
		log.Printf("%s\n", name[0])     //xuhy
		log.Printf("%s\n", name[1])     //jason
    })
}
```
或者使用`Get()`函数，获取参数切片的第一个数据
```go
func main() {
    http.HandleFunc("/order", func(w http.ResponseWriter, r *http.Request){
        query := r.URL.Query()
        
        name := query.Get("name")
        log.Printf("%s\n", name)    //xuhy
    })
}
```

## 获取Body

另外一种常见的传值方式就是将数据存放于请求的Body当中，同样在`Request`中可以找到`Body`字段，它是`io.ReadCloser`接口类型。

```go
func main() {
	//获取Body中的数据
	http.HandleFunc("/order/add", func(w http.ResponseWriter, r *http.Request){
		defer r.Body.Close()
		
		body, _ := ioutil.ReadAll(r.Body) //读取Body内容
		log.Printf("%s\n", body)
	})
}
```

POST请求中的表单数据是常见的情形，接下来详细地介绍如何获取各种情况下的表单数据。

## 获取表单数据
通过表单发送数据，数据都是以键值对的形式发送出去的。当服务器接收到请求时，请求走到相应的`Handler`后，从`Handler`的`Request`参数中可以获取表单数据，获取的方法针对不同的表单形式有几种。  
为了得到表单中的数据，要先调用`ParseForm`或`ParseMultipartForm`函数先解析`Request`中的数据，随后便可以使用三个字段来读取表单数据。如下
* Form
* PostForm
* MultipartForm  
下面是一个简单的示例。前端代码就简单放一个Form，包含三个`<input>`标签。
```html
<form action="http://localhost:8080/register" method="post"
    enctype="application/x-www-form-urlencoded">
    <div class="form-group">
        <label for="emailTxt">Email address: </label>
        <input type="email" class="form-control" name="email" id="emailTxt" placeholder="Email">
    </div>
    <div class="form-group">
        <label for="userNameTxt">User Name</label>
        <input type="text" class="form-control" name="userName" id="userNameTxt" placeholder="User Name">
    </div>
    <div class="checkbox">
        <label>
            <input type="checkbox" name="checkOut"> Check me out
        </label>
    </div>
    <button type="submit" class="btn btn-primary">Submit</button>
</form>
```

#### Form
`Request`中的`Form`字段是`map[string][]string`类型，map的key是input标签的`name`属性，map的`value`是`[]string`类型，示例中的html代码，存放的就是`input`标签的`value`属性。  
读取前端提交来的Form中的数据可以在解析完后（`r.ParseForm()`），访问`Request`的`Form`字段或者使用`Request`的`FormValue()`方法来读取相应的值，`FormValue()`方法会返回切片的第一个值，即`request.Form["userName"][0]`和`request.FormValue("userName")`是等效的。
```go
func main() {
	http.HandleFunc("/register", func(w http.ResponseWriter, r *http.Request) {
		//解析
		r.ParseForm()

		fmt.Fprintln(w, "读值方式1")
		fmt.Fprintln(w, fmt.Sprintf("user name : %v", r.Form["userName"]))
		fmt.Fprintln(w, fmt.Sprintf("email : %v", r.Form["email"]))
		fmt.Fprintln(w, fmt.Sprintf("checkbox checked : %v", r.Form["checkOut"]))

		fmt.Fprintln(w, "读值方式2")
		fmt.Fprintln(w, fmt.Sprintf("user name : %v", r.FormValue("userName")))
		fmt.Fprintln(w, fmt.Sprintf("email : %v", r.FormValue("email")))
		fmt.Fprintln(w, fmt.Sprintf("checkbox checked : %v", r.FormValue("checkOut")))
	})

	http.ListenAndServe("localhost:8080", nil)
}
```
* 提交后看到的输出：
```html
读值方式1
user name : [123]
email : [583209544@qq.com]
checkbox checked : [on]
读值方式2
user name : 123
email : 583209544@qq.com
checkbox checked : on
```
最常见的读取表单中的数据就是这样，但是如果在表单提交的地址中加上QueryString，并且QueryString和表单的键值对中存在同样的键时，`request.Form`中的值即string切片中便会存在两个值的情况，其中表单的值会在前，QueryString的值在后。然而如果读取表单数据用的不是`request.Form`而是`request.PostForm`，便不会读取到除了表单以外的数据。

#### PostForm

如果现将表单的action改为`action="http://localhost:8080/register?userName=Admin"`，即QueryString中增加了一个与表单相同的key即userName。那么使用`request.Form`和`request.PostForm`读取数据的区别可见。

```go
func main() {
	http.HandleFunc("/register", func(w http.ResponseWriter, r *http.Request) {
		//解析
		r.ParseForm()

		fmt.Fprintln(w, "使用Form读取: ")
		fmt.Fprintln(w, r.Form)

		fmt.Fprintln(w, "使用PostForm读取: ")
		fmt.Fprintln(w, r.PostForm)
	})

	http.ListenAndServe("localhost:8080", nil)
}
```

*提交后看到的输出：

```
使用Form读取: 
map[checkOut:[on] email:[583209544@qq.com] userName:[123 Admin]]
使用PostForm读取: 
map[checkOut:[on] email:[583209544@qq.com] userName:[123]]
```

`r.PostForm`中没有显示QueryString中的值。与`Request`的`FormValue()`方法类似，`Request`中还有一个`PostFormValue()`方法，即是读取PostForm中值的方法。  
再改变一下条件，如果表单数据要上传不仅仅是字符串数据，还要上传文件，那么表单的编码类型即`encType`就不能是默认的`application/x-www-form-urlencoded`而要改成`multipart/form-data`。但是这么一改会发现，`request.Form`或者`request.PostForm`读取不到任何表单数据，通过`request.PostFormValue()`只能读取string数据，上传的文件数据是无法读取的。这种情况下就需要使用`request.MultipartForm`来读取了。

#### MultipartForm

与`request.Form`不同，使用`request.MultipartForm`前的解析方法需换为使用`r.ParseMultipartForm()`来解析。
* ParseMultipartForm的函数签名

```go
func (r *Request) ParseMultipartForm(maxMemory int64) error
```

`r.ParseMultipartForm()`需要传入一个int值来设定要读取的数据的长度。`request.MultipartForm`也不再是一个map类型，而是`multipart.Form`的指针类型，`multipart.Form`其实是一个struct。

* formdata.go 中包含 multipart.Form 的类型声明

```go
type Form struct {
	Value map[string][]string
	File  map[string][]*FileHeader
}
```

也就是说`request.MultipartForm`可访问两个字段，并且都是map类型。
1. Value：放的都是表单里的字符串数据，那功能就和之前的r.PostForm差不多
2. File：放的是文件数据

现将`<form>`中的编码类型改为`enctype="multipart/form-data`，并添加一个`<input id="avatarFile" type="file" name="avatar"/>`来上传文件

```html
<form action="http://localhost:8080/register?userName=admin" method="post"
enctype="multipart/form-data">
	<div class="form-group">
		<label for="emailTxt">Email address: </label>
		<input id="emailTxt" type="email" class="form-control" name="email" placeholder="Email">
	</div>
	<div class="form-group">
		<label for="userNameTxt">User Name</label>
		<input id="userNameTxt" type="text" class="form-control" name="userName"
			placeholder="User Name">
	</div>
	<div class="checkbox">
		<label>
			<input type="checkbox" name="checkOut"> Check me out
		</label>
	</div>
	<div class="form-group">
		<label for="avatarFile" class="btn btn-secondary">Avatar</label>
		<input id="avatarFile" type="file" name="avatar" class="d-none"/>
	</div>
	<button type="submit" class="btn btn-primary">Submit</button>
</form>
```

在服务端从`MultipartForm.File`中读取文件可使用`Open`方法。将表单中的文件数据保存到本地，下面有个示例。

```go
package main

import (
	"fmt"
	"net/http"
	"os"
)

func main() {
	http.HandleFunc("/register", func(w http.ResponseWriter, r *http.Request) {
		//先解析
		//先解析
		r.ParseMultipartForm(1024 * 1024)
		// 再试试PostFormValue方法
		fmt.Fprintln(w, fmt.Sprintf("user name : %v", r.PostFormValue("userName")))
		fmt.Fprintln(w, fmt.Sprintf("avatar : %v", r.PostFormValue("avatar")))
		// 读取MultipartForm
		fmt.Fprintln(w, fmt.Sprintf("user name : %v", r.MultipartForm.Value["userName"]))
		// 取出文件保存到本地
		if avatar, ok := r.MultipartForm.File["avatar"]; ok {
			fh := avatar[0]
			file, err := fh.Open()

			fileBuff := make([]byte, fh.Size)
			if err == nil {
				_, err := file.Read(fileBuff)
				if err == nil {
					file, err := os.Create("avatar.jpg")
					defer file.Close()
					if err == nil {
						file.Write(fileBuff)
						fmt.Fprintln(w, "avatar : saved")
					}
				}
			}
		} else {
			fmt.Fprintln(w, "avatar : no file")
		}
	})

	_ = http.ListenAndServe("localhost:8080", nil)
}
```
其实如果单纯的读取上传的单独文件，可以直接使用`r.FormFile()`来获取。`FormFile()`方法同时返回文件和文件头作为结果。即可以将

```go
fh := r.MultipartForm.File["avatar"][0]
file, err := fh.Open()
```

换成下面的写法。

```go
file, _, err := r.FormFile("avatar")
```