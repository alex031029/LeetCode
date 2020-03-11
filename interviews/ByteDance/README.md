# Round 1

从输入URL到呈现页面都发生了什么

https://stackoverflow.com/questions/2092527/what-happens-when-you-type-in-a-url-in-browser

Attention: this is an extremely rough and oversimplified sketch, assuming the simplest possible HTTP request (no HTTPS, no HTTP2, no extras), simplest possible DNS, no proxies, single-stack IPv4, one HTTP request only, a simple HTTP server on the other end, and no problems in any step. This is, for most contemporary intents and purposes, an unrealistic scenario; all of these are far more complex in actual use, and the tech stack has become an order of magnitude more complicated since this was written. With this in mind, the following timeline is still somewhat valid:

1. browser checks cache; if requested object is in cache and is fresh, skip to #9
2. browser asks OS for server's IP address
3. OS makes a DNS lookup and replies the IP address to the browser
4. browser opens a TCP connection to server (this step is much more complex with HTTPS)
5. browser sends the HTTP request through TCP connection
6. browser receives HTTP response and may close the TCP connection, or reuse it for another request
7. browser checks if the response is a redirect or a conditional response (3xx result status codes), authorization request (401), error (4xx and 5xx), etc.; these are handled differently from normal responses (2xx)
8. if cacheable, response is stored in cache
9. browser decodes response (e.g. if it's gzipped)
10. browser determines what to do with response (e.g. is it a HTML page, is it an image, is it a sound clip?)
11. browser renders response, or offers a download dialog for unrecognized types
    
Again, discussion of each of these points have filled countless pages; take this only as a summary, abridged for the sake of clarity. Also, there are many other things happening in parallel to this (processing typed-in address, speculative prefetching, adding page to browser history, displaying progress to user, notifying plugins and extensions, rendering the page while it's downloading, pipelining, connection tracking for keep-alive, cookie management, checking for malicious content etc.) - and the whole operation gets an order of magnitude more complex with HTTPS (certificates and ciphers and pinning, oh my!).


# Round 3

## TCP与UDP的应用场景。尤其是UDP也可以设置ACK

## 数据结构相关
头条有10亿条纪录，分别储存在1000个文件中，每个文件100万条纪录。每条记录包括了了一个用户id与他的活跃度。设计一个算法获得前10000名活跃用户的id。

我的思路是利用最小堆。这个堆的大小维持在10000，每次有新的数据读入的时候，如果比堆顶元素小，则无视。否则修改堆顶元素为新读入的数据，再自顶向下堆化。

## 多线程相关
5000个TC
