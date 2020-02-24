# RESTful and RPC

这俩居然不是一个东西！

https://stackoverflow.com/questions/26830431/web-service-differences-between-rest-and-rpc

https://www.zhihu.com/question/28557115/answer/48094438

REST API一般更简洁，但是RPC效率更高。

## RESTful

RESTful的特性

* 资源(Resources)：网络上的一个实体，或者说是网络上的一个具体信息。它可以是一段文本、一张图片、一首歌曲、一种服务，总之就是一个具体的存在。可以用一个URI（统一资源定位符）指向它，每种资源对应一个特性的URI。要获取这个资源，访问它的URI就可以，因此URI即为每一个资源的独一无二的识别符。

* 表现层(Representation)：把资源具体呈现出来的形式，叫做它的表现层(Representation)。比如，文本可以用txt格式表现，也可以用HTML格式、XML格式、JSON格式表现，甚至可以采用二进制格式。

* 状态转换(State Transfer)：每发出一个请求，就代表了客户端和服务器的一次交互过程。HTTP协议，是一个无状态协议，即所有的状态都保存在服务器端。因此，如果客户端想要操作服务器，必须通过某种手段，让服务器端发生“状态转换”(State Transfer)。而这种转换是建立在表现层之上的，所以就是“表现层状态转换”。具体说，就是HTTP协议里面，四个表示操作方式的动词：GET、POST、PUT、DELETE。他们分别对应四种基本操作：GET用来获取资源，POST用来新建资源，PUT用来更新资源，DELETE用来删除资源。


这个总结不错：
* 看Url就知道要什么 （URL一看就有api的关键词，以及均为名词）
* 看http method就知道干什么 （GET表示查询，POST表示创建，PUT表示更新，DELETE表示删除）
* 看http status code就知道结果如何
