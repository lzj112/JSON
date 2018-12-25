// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is an internal header file, you should not include this.

#ifndef MUDUO_NET_ACCEPTOR_H
#define MUDUO_NET_ACCEPTOR_H
 
#include <functional>

#include <muduo/net/Channel.h>
#include <muduo/net/Socket.h>

namespace muduo
{
namespace net
{

class EventLoop;
class InetAddress;

///
/// Acceptor of incoming TCP connections.
///
class Acceptor : noncopyable
{
 public:
  typedef std::function<void (int sockfd, const InetAddress&)> NewConnectionCallback;

  Acceptor(EventLoop* loop, const InetAddress& listenAddr, bool reuseport);
  ~Acceptor();

  void setNewConnectionCallback(const NewConnectionCallback& cb)
  { newConnectionCallback_ = cb; }

  bool listenning() const { return listenning_; }

  //执行socket(),bind(),listen()
  void listen();

 private:
 //处理可读事件
  void handleRead();

  EventLoop* loop_;
  //RAII句柄,Acceptor的acceptSocket_是一个listening socket
  Socket acceptSocket_;  
  //用于观察该socket上的可读事件,回调Acceptor::handleRead(),
  //该函数调用accept接收新连接,并调用用户的回调函数
  Channel acceptChannel_; 
  NewConnectionCallback newConnectionCallback_;
  bool listenning_;
  int idleFd_;
};

}  // namespace net
}  // namespace muduo

#endif  // MUDUO_NET_ACCEPTOR_H
