
/**
******************************************************************************
* @file   webpge.h
* @author  WIZnet Software Team 
* @version V1.0
* @date    2024
* @brief   web���������ڵ�����
* @attention  
******************************************************************************
**/
#ifndef __WEBPAGE_H
#define __WEBPAGE_H

#define style ""


#define XT_INDEX "\
<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
<meta charset=\"GB2312\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
<title>�������ص�ز���ƽ̨</title>\
<style>\
* {\
padding: 0;\
margin: 0;\
}\
html {\
height: 100%;\
}\
body {\
background-image: linear-gradient(to bottom right, rgb(114, 135, 254), rgb(130, 88, 186));\
}\
.login-container {\
width: 600px;\
height: 315px;\
margin: 0 auto;\
margin-top: 10%;\
border-radius: 15px;\
box-shadow: 0 10px 50px 0px rbg(59, 45, 159);\
background-color: rgb(95, 76, 194);\
}\
.left-container {\
display: inline-block;\
width: 330px;\
border-top-left-radius: 15px;\
border-bottom-left-radius: 15px;\
padding: 60px;\
background-image: linear-gradient(to bottom right, rgb(118, 76, 163), rgb(92, 103, 211));\
}\
.title {\
color: #fff;\
font-size: 18px;\
font-weight: 200;\
}\
.title span {\
border-bottom: 3px solid rgb(237, 221, 22);\
}\
.input-container {\
padding: 20px 0;\
}\
input {\
border: 0;\
background: none;\
outline: none;\
color: #fff;\
margin: 20px 0;\
display: block;\
width: 100%;\
padding: 5px 0;\
transition: .2s;\
border-bottom: 1px solid rgb(199, 191, 219);\
}\
input:hover {\
border-bottom-color: #fff;\
}\
::-webkit-input-placeholder {\
color: rgb(199, 191, 219);\
}\
.message-container {\
font-size: 14px;\
transition: .2s;\
color: rgb(199, 191, 219);\
cursor: pointer;\
}\
.message-container:hover {\
color: #fff;\
}\
.right-container {\
width: 145px;\
display: inline-block;\
height: calc(100% - 120px);\
vertical-align: top;\
padding: 60px 0;\
}\
.regist-container {\
text-align: center;\
color: #fff;\
font-size: 18px;\
font-weight: 200;\
}\
.regist-container span {\
border-bottom: 3px solid rgb(237, 221, 22);\
}\
.action-container {\
font-size: 12px;\
color: #fff;\
text-align: center;\
position: relative;\
top: 200px;\
}\
.action-container span {\
border: 1px solid rgb(237, 221, 22);\
padding: 12px;\
display: inline;\
line-height: 20px;\
border-radius: 20px;\
position: absolute;\
bottom: 10px;\
left: calc(72px - 20px);\
transition: .2s;\
cursor: pointer;\
}\
.action-container span:hover {\
background-color: rgb(237, 221, 22);\
color: rgb(95, 76, 194);\
}\
</style>\
</head>\
<body>\
<div class=\"login-container\">\
<div class=\"left-container\">\
<div class=\"title\"><span>�������ص�ز���ƽ̨</span></div>\
<div class=\"input-container\">\
<input id=\"userName\" type=\"text\" name=\"username\" placeholder=\"�û���\">\
<input id=\"password\"type=\"password\" name=\"password\" placeholder=\"����\">\
</div>\
<div class=\"message-container\">\
<span>��������</span>\
</div>\
</div>\
<div class=\"right-container\">\
<div class=\"regist-container\">\
<span class=\"regist\">ע��</span>\
</div>\
<div class=\"action-container\">\
<span onclick=\"login()\">�ύ</span>\
</div>\
</div>\
</div>\
<script type=\"text/javascript\">\
function SetCookie(cookieName, cookieValue, nDays) {\
var today = new Date();\
var expire = new Date();\
if (nDays == null || nDays == 0) nDays = 1;\
expire.setTime(today.getTime() + 300000 * nDays);\
document.cookie = cookieName + \"=\" + escape(cookieValue)\
+ \";expires=\" + expire.toGMTString();\
}\
function login() {\
var username = document.getElementById(\"userName\").value;\
var password = document.getElementById(\"password\").value;\
if (username == \"root\" && password == \"root\") {\
SetCookie(\"username\", username, 1);\
SetCookie(\"password\", password, 1);\
document.location = \"XT_Main_Weight.html\";\
} else if (username == \"\" || password == \"\") {\
alert(\"�����û���������\");\
} else {\
alert(\"�û����������������\");\
}\
}\
</script>\
</body>\
</html>\
"


#define Main_weight "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:130px;font-size: 22px;}\
select{margin-left:50px;width:100px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
*{\
margin: 0;\
padding: 0;\
}\
.xtinput input{\
appearance: none;\
text-align: center;\
height: 36px;\
width: 199px;\
border-radius: 15px;\
border: 0px solid #fff;\
padding: 0 8px;\
outline: 0;\
letter-spacing: 1px;\
color: #0a0a0a;\
font-weight: 600;\
background: rgba(0, 0, 0, 0.1);\
border: 1px solid rgba(20, 20, 20, 0.15);\
box-shadow: 0 2px 3px 0 rgba(0,0,0,.1) inset;\
text-shadow: 0 1px 2px rgba(0,0,0,.1);\
-o-transition: all .2s;\
-moz-transition: all .2s;\
-webkit-transition: all .2s;\
-ms-transition: all .2s;\
}\
.xtinput input {\
box-shadow: 0 0 5px 4px rgba(0, 0, 0,0.1);\
}\
.datainput input{\
width: 100px;\
background-color: #f3f4f5;\
background-repeat: no-repeat;\
background-position: center;\
border: none;\
text-align:left;\
}\
.long input{\
width: 150px;\
background-color: #f3f4f5;\
background-repeat: no-repeat;\
background-position: center;\
border: none;\
text-align:left;\
}\
#wrapper{\
width: 1200px;\
height: 500px;\
}\
body {\
font-size: 12px;\
font-family: \"΢���ź�\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li class=\"active\">\
<a href=\"\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li>\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li>\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û�:LZH , ���:����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>�㵱ǰ����λ��:��ҳ > ��̨����</p>\
</div>\
<div id='main'>\
<div style=\"margin-left: 100px; margin-top: 150px;\">\
<h2 style=\"margin-left: 70px; margin-top: -30px;\">��ǰ����</h2>\
<br></br>\
<div class=\"xtinput\"><input disabled style=\"margin-top: -40px;\" value=\"��ɽ��\"></div>\
<br></br>\
<h2 style=\"margin-left: 65px; margin-top: 30px;\">��ǰ��γ��</h2>\
<br></br>\
<p  class=\"xtinput\" style=\"font-size: 18px;\">X:<input disabled style=\"margin-left:25px; margin-top: -40px;\" value=\"113.40254563102722\" ></p>\
<br></br>\
<p  class=\"xtinput\" style=\"font-size: 18px;\">Y:<input class:xtinput disabled style=\"margin-left:25px; margin-top: -40px;\" value=\"22.44939148184495\"></p>\
</div>\
<div style=\"margin-left: 460px; margin-top: -402px;\" id=\"wrapper\"></div>\
<br></br>\
<h1 style=\"margin-left: 100px;\">ϵͳ����:</h1>\
<br></br>\
<div style=\"margin-left: 100px;\">\
<p>����1:</p><p class=\"datainput\">������:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"115200\">\
����λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"8\">\
ֹͣλ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1\">\
У��λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"��У��\"></p>\
<p>����2:</p><p class=\"datainput\">������:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"9600\">\
����λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"8\">\
ֹͣλ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1\">\
У��λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"��У��\"></p>\
<p>����3:</p><p class=\"datainput\">������:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"9600\">\
����λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"8\">\
ֹͣλ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1\">\
У��λ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"��У��\"></p>\
<p>AD1:</p><p class=\"datainput\">����:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"��ѹ\">\
��Сֵ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"10\">\
���ֵ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"200\"></p>\
<p>AD2:</p><p class=\"datainput\">����:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"����\">\
��Сֵ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1\">\
���ֵ:<input disabled style=\"margin-left: 10px;\" type=\"text\" value=\"10\"></p>\
<div style=\"margin-left: 750px; margin-top: -165px;\">\
<p>��̫��:</p><p class=\"datainput\">����IP:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"10.193.6.206\">\
��������:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"255.255.255.0\">\
����:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"10.193.6.1\">\
DNS:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"8.8.8.8\"></p>\
<p>��̫��MQTT:</p><p class=\"datainput\">Զ��IP:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"10.192.178.87\">\
Զ�̶˿�:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1883\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��ID:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"SUN_000001_ETH\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��USER:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value\"GW_ZHONGTNSW\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��PWD:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"**************\"></p>\
<p>4G����MQTT:</p><p class=\"datainput\">Զ��ADDR:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"dt.ztn-tech.com\">\
Զ�̶˿�:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"1883\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��ID:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"SolarTestT00011_4G\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��USER:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"SolarTest_22AB562F\"></p>\
<p style=\"margin-top: 2px;\" class=\"long\">Զ��PWD:<input  disabled style=\"margin-left: 10px;\" type=\"text\" value=\"**************\"></p>\
</div>\
</div>\
</div>\
</div>\
</div>\
</body>\
<script type=\"text/javascript\" src=\"https://webapi.amap.com/maps?v=1.4.8&key=7eb57c65eb11506560301ffeacce9800\"></script> \
<script>\
window.onload = function(){\
var map = new AMap.Map(\"wrapper\", {\
zoom: 15,\
center: [113.40254563102722, 22.44939148184495]\
});\
var marker = new AMap.Marker({\
position: new AMap.LngLat(113.40254563102722, 22.44939148184495)\
title: \"λ�ñ���\"\
});\
map.add(marker);\
}\
</script>\
</html>\
"

#define Net_Config_Html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<script type=\"text/javascript\" src=\"https://webapi.amap.com/maps?v=1.4.8&key=048ff1e24979189020d16c31a462394a\"></script>\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:130px;font-size: 22px;}\
input{width:240px;height:30px;border-radius: 10px;text-align:center;}\
select{margin-left:50px;width:100px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
* {\
margin: 0;\
padding: 0;\
}\
body {\
font-size: 12px;\
font-family: \"΢���ź�\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
<script>\
function $(id) { return document.getElementById(id); };\
function settingsCallback(o) {\
if ($('txtIp')) $('txtIp').value = o.ip;\
if ($('txtSub')) $('txtSub').value = o.sub;\
if ($('txtGw')) $('txtGw').value = o.gw;\
if ($('txtSIp')) $('txtSIp').value = o.sip;\
if ($('txtstopic')) $('txtstopic').value = o.stopic;\
if ($('txtLPORT')) $('txtLPORT').value = o.lport;\
if ($('txtptopic')) $('txtptopic').value = o.ptopic;\
if ($('txtRPORT')) $('txtRPORT').value = o.rport;\
if ($('txtUser')) $('txtUser').value = o.user;\
if ($('txtCID')) $('txtCID').value = o.cid;\
if ($('txtPassword')) $('txtPassword').value = o.password;\
};\
</script>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li>\
<a href=\"XT_Main_Weight.html\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li>\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û�:LZH , ���:����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>�㵱ǰ����λ��:��ҳ >��������/p>\
</div>\
<div id='main'>\
<div style='background:snow; display:block;padding:100px 120px;'>\
<h3>������������</h3>\
<h4>����ӿ�����</h4>\
<p> <br></p>\
<p> <br></p>\
<form id='frmSetting' method='POST'action='config.cgi' >\
<p><label for='txtIp'>�汾:</label><input type='text' id='txtVer' name='ver'\
disabled='disabled' value = 'ICOM_V1.0.0' />\
</p>\
<p style=\"font-size: 22px;margin-top:-35px;margin-left:600px;\"><lable>����ģʽ:</label>\
<select id=\"netmode\" style=\"width:150px\" name='test' id='test'><option value='1'>TCP SERVER</option>\
<option selected value='2'>TCP CLIENT</option><option selected value='3'>��̩��</option>\
<option selected value='4'>�Ϸ�����</option><option selected value='5'>��ͨ</option></select>\
</p>\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtIp'>MAC:</label><input type='text' id='txtMac' name='mac'\
size='16' disabled='disabled' value = '78.83.68.88.56.72'/>\
</p>\
<p style=\"margin-top:-35px;margin-left:600px;\"><label for='txtSIp'>Զ��IP:</label><input type='text' id='txtSIp' name='sp' size='16'></p>\
<p style=\"margin-top:-35px;margin-left:1020px;\"><label for='txtstopic'>��������:</label><input type='text' id='txtstopic' name='stopic' size='16' >\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtIp'>IP:</label><input type='text' id='txtIp' name='ip' size='16'></p>\
<p style=\"margin-top:-35px;margin-left:600px;\"><label for='txtLPORT'>���ض˿�:</label><input type='text' id='txtLPORT' name='lport' size='16'>\
<p style=\"margin-top:-35px;margin-left:1020px;\"><label for='txtptopic'>��������:</label><input type='text' id='txtptopic' name='ptopic' size='16'>\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtSub'>����:</label><input type='text' id='txtSub' name='sub'  size='16'></p>\
<p style=\"margin-top:-35px;margin-left:600px;\"><label for='txtRPORT'>Զ�̶˿�:</label><input type='text' id='txtRPORT' name='rport' size='16'>\
<p style=\"margin-top:-35px;margin-left:1020px;\"><label for='txtUser'>�û���:</label><input type='text' id='txtUser' name='user' size='16'>\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtGw'>����:</label><input type='text' id='txtGw' name='gw' size='16'></p>\
<p style=\"margin-top:-35px;margin-left:600px;\"><label for='txtCID'>�ͻ���ID:</label><input type='text' id='txtCID' name='clientid' size='16'>\
<p style=\"margin-top:-35px;margin-left:1020px;\"><label for='txtPassword'>����:</label><input type='text' id='txtPassword' name='pwd' size='16'>\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <input style=\"width:150px;height:50px;border-radius: 10px;margin-left:600px;\" type ='submit' value = '����'></p>\
</form>\
</div>\
</div>\
</div>\
</div>\
<script type='text/javascript' src='w5500.js'></script>\
</body>\
</html>\
<script>\
var del = document.getElementsByClassName('a_del')\
for (let i = 0; i < del.length; i++) {\
del[i].onclick = function () {\
del[i].parentNode.parentNode.parentNode.remove()\
}\
}\
</script>\
"

#define Usart_Config_html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<script type=\"text/javascript\" src=\"https://webapi.amap.com/maps?v=1.4.8&key=048ff1e24979189020d16c31a462394a\"></script>\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:130px;font-size: 22px;}\
input{width:170px;height:30px;border-radius: 10px;text-align:center;}\
select{margin-left:30px;width:130px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
* {\
margin: 0;\
padding: 0;\
}\
body {\
font-size: 12px;\
font-family: \"΢���ź�\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
<script>\
function $(id) { return document.getElementById(id); };\
function settingsUartCallback(o) {\
if ($('txtBAUT1')) $('txtBAUT1').value = o.baut1;\
if ($('txtBAUT2')) $('txtBAUT2').value = o.baut2;\
if ($('txtBAUT3')) $('txtBAUT3').value = o.baut3;\
if ($('txtDATA1')) $('txtDATA1').value = o.data1;\
if ($('txtDATA2')) $('txtDATA2').value = o.data2;\
if ($('txtDATA3')) $('txtDATA3').value = o.data3;\
if ($('txtSTOP1')) $('txtSTOP1').value = o.stop1;\
if ($('txtSTOP2')) $('txtSTOP2').value = o.stop2;\
if ($('txtSTOP3')) $('txtSTOP3').value = o.stop3;\
};\
</script>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li>\
<a href=\"XT_Main_Weight.html\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li>\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li>\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û�:LZH , ���:����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>�㵱ǰ����λ��:��ҳ >��������/p>\
</div>\
<div id='main'>\
<div style='background:snow; display:block;padding:100px 120px;'>\
<h3>��������</h3>\
<p> <br></p>\
<p> <br></p>\
</p>\
<form id='frmSetting' method='POST'action='Uartconfig.cgi' >\
<p><label for='txtUART1'>����:</label><input type='text' id='txtUART1' name='uart1' disabled='disabled' value = '485����1' ></p>\
<p style=\"margin-top:-35px;margin-left:450px;\"><label for='txtUART2'>����:</label><input type='text' id='txtUART2' name='uart2' size='16' disabled='disabled' value = '485����2' >\
<p style=\"margin-top:-35px;margin-left:900px;\"><label for='txtUART3'>����:</label><input type='text' id='txtUART3' name='uart3' size='16' disabled='disabled' value = '232����' >\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtBAUT1'>������:</label><input type='text' id='txtBAUT1' name='baut1' ></p>\
<p style=\"margin-top:-35px;margin-left:450px;\"><label for='txtBAUT2'>������:</label><input type='text' id='txtBAUT2' name='baut2' size='16' >\
<p style=\"margin-top:-35px;margin-left:900px;\"><label for='txtBAUT3'>������:</label><input type='text' id='txtBAUT3' name='baut3' size='16' >\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtDATA1'>����λ:</label><input type='text' id='txtDATA1' name='data1' size='16'></p>\
<p style=\"margin-top:-35px;margin-left:450px;\"><label for='txtDATA2'>����λ:</label><input type='text' id='txtDATA2' name='data2' size='16' >\
<p style=\"margin-top:-35px;margin-left:900px;\"><label for='txtDATA3'>����λ:</label><input type='text' id='txtDATA3' name='data3' size='16' >\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtSTOP1'>ֹͣλ:</label><input type='text' id='txtSTOP1' name='stop1' size='16'></p>\
<p style=\"margin-top:-35px;margin-left:450px;\"><label for='txtSTOP2'>ֹͣλ:</label><input type='text' id='txtSTOP2' name='stop2' size='16' >\
<p style=\"margin-top:-35px;margin-left:900px;\"><label for='txtSTOP3'>ֹͣλ:</label><input type='text' id='txtSTOP3' name='stop3' size='16' >\
<p> <br></p>\
<p> <br></p>\
<p style=\"font-size: 22px;\"><lable> У��λ:</label>\
<select style=\"margin-left:30px\" id=\"crc1\" style=\"width:150px\" name='test'><option value='1'>��У��</option>\
<option selected value='2'>��У��</option><option selected value='3'>żУ��</option></select>\
<p style=\"font-size: 22px;margin-top:-35px;margin-left:450px;\"><lable>У��λ :</label>\
<select id=\"crc2\" style=\"width:150px\" name='test'><option value='1'>��У��</option>\
<option selected value='2'>��У��</option><option selected value='3'>żУ��</option></select>\
<p style=\"font-size: 22px;margin-top:-35px;margin-left:900px;\"><lable> У��λ:</label>\
<select id=\"crc3\" style=\"width:150px\" name='test'><option value='1'>��У��</option>\
<option selected value='2'>��У��</option><option selected value='3'>żУ��</option></select>\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <input style=\"width:150px;height:50px;border-radius: 10px;margin-left:600px;\" type ='submit' value = '����'></p>\
</form>\
</div>\
</div>\
</div>\
</div>\
<script type='text/javascript' src='Uartw5500.js'></script>\
</body>\
</html>\
<script>\
var del = document.getElementsByClassName('a_del')\
for (let i = 0; i < del.length; i++) {\
del[i].onclick = function () {\
del[i].parentNode.parentNode.parentNode.remove()\
}\
}\
</script>\
"


#define Modbus_Config_html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:100px;font-size: 22px;}\
input{width:110px;height:30px;border-radius: 10px;text-align:center;}\
select{margin-left:10px;width:130px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
button{\
background-color:#f66f6a;\
color:white;\
width: 80px;\
height: 30px;\
border:0;\
font-size: 1px;\
border-radius: 3px;\
}\
button:hover{\
background-color: #a54b4a;\
}\
table{\
width: 100%;\
border-collapse: collapse;\
}\
table caption{\
font-size: 2em;\
font-weight: bold;\
margin: 1em 0;\
}\
th,td{\
border: 1px solid #999;\
text-align: center;\
padding: 20px 0;\
}\
table thead tr{\
background-color: #008c8c;\
color: #eee;\
}\
table tbody tr:nth-child(odd){\
background-color: #eee;\
}\
table tbody tr:hover{\
background-color: #ccc;\
}\
table tbody tr td:first-child{\
color: #f40;\
}\
table tfoot tr td{\
text-align: right;\
padding-right: 20px;\
}\
.mybox{\
margin: auto;\
position: absolute;\
left: 100px;\
right: 0;\
bottom: 0;\
}\
.ground{\
display: none;\
box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);\
width: 400px;\
height: 500px;\
border-radius: 20px;\
border: 2px solid #fff;\
background: #fff;\
margin: auto;\
position: absolute;\
top: -200px;\
left: 0;\
right: 0;\
bottom: 0;\
}\
.ground1{\
position: relative;\
}\
.headline{\
margin: auto;\
position: absolute;\
top: 10px;\
left: 175px;\
right: 0;\
bottom: 0;\
}\
.text{\
margin: auto;\
position: absolute;\
top: 110px;\
left: 50px;\
right: 0;\
bottom: 0;\
}\
.yes,.no{\
border: 2px solid #87cefa;\
background: #87cefa;\
border-radius: 11px;\
width: 65px;\
height: 38px;\
font-size: 17px;\
}\
.yes{\
margin: auto;\
position: absolute;\
top: 450px;\
left: -80px;\
right: 0;\
bottom: 0;\
}\
.no{\
margin: auto;\
position: absolute;\
top: 450px;\
left: 80px;\
right: 0;\
bottom: 0;\
}\
.niceButton5 {\
display: inline-block;\
border-radius: 15px;\
background-color: #f4511e;\
border: none;\
color: #ffff;\
text-align: center;\
font-size: 13px;\
font-weight: 200;\
padding: 9px;\
width: 100px;\
transition: all 0.5s;\
cursor: pointer;\
margin: 5px;\
vertical-align: middle;\
margin-left: 10px;\
}\
.niceButton5 span {\
cursor: pointer;\
display: inline-block;\
position: relative;\
transition: 0.5s;\
}\
.niceButton5 span::after {\
content: \">\";\
position: absolute;\
opacity: 0;\
top: 0;\
right: -20px;\
transition: 0.5s;\
}\
.niceButton5:hover span {\
padding-right: 10px;\
}\
.niceButton5:hover span::after {\
opacity: 1;\
right: 0;\
}\
* {\
margin: 0;\
padding: 0;\
}\
body {\
font-size: 12px;\
font-family: \"????\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat 0 -51px;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat -386px -15px;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
<script>\
window.myid = 1;\
var modbus_count = 0;\
function $(id) { return document.getElementById(id); }\
function addTr(myAddr,myValue){\
var tb = document.getElementById(\"task\");\
var tg = document.createElement(\"tbody\");\
var tt = document.createElement(\"tr\");\
var td1 = document.createElement(\"td\");\
var td2 = document.createElement(\"td\");\
var td3 = document.createElement(\"td\");\
var td5 = document.createElement(\"td\");\
var td4 = document.createElement(\"td\");\
var pa = document.createElement(\"td\");\
var pb = document.createElement(\"td\");\
var bt1 = document.createElement(\"button\");\
var bt2 = document.createElement(\"button\");\
var sp1 = document.createElement(\"span\");\
var sp2 = document.createElement(\"span\");\
window.addr = document.getElementById(\"txtSid\").value;\
window.pos = document.getElementById(\"txtADDR\").value;\
pa.setAttribute(\"style\", \"width: 550px;\");\
bt1.setAttribute(\"style\", \"margin-left: -200px;\");\
bt1.setAttribute(\"class\", \"niceButton5\");\
bt1.setAttribute(\"onclick\", \"Edittr(this)\");\
bt1.setAttribute(\"href\", \"javascript:void(0)\");\
sp1.innerHTML = \"�༭\";\
bt1.appendChild(sp1);\
bt2.setAttribute(\"style\", \"margin-right: -200px;\");\
bt2.setAttribute(\"class\", \"niceButton5\");\
bt2.setAttribute(\"onclick\", \"deleteTr(this)\");\
bt2.setAttribute(\"href\", \"javascript:void(0)\");\
sp2.innerHTML = \"ɾ��\";\
bt2.appendChild(sp2);\
pa.appendChild(bt1);\
pa.appendChild(bt2);\
td1.innerHTML = window.myid;\
window.myid = window.myid+1;\
td2.innerHTML = 1;\
td3.innerHTML = myAddr;\
td5.innerHTML = myValue;\
tt.appendChild(td1);\
tt.appendChild(td2);\
tt.appendChild(td3);\
tt.appendChild(td5);\
tt.appendChild(pa);\
tg.appendChild(tt);\
tb.appendChild(tg);\
}\
function settingsTaskCallback(o) {\
for(var i = 0 ; i < o.modbus_count ; i++){\
addTr(o.Addr[i],o.value[i]);\
}\
}\
</script>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li >\
<a href=\"\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li>\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û�:LZH , ���:ϵͳ����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>�����ڵ�λ��:��ҳ > ��������</p>\
</div>\
<div id='main'>\
<div style='background:snow; display:block;padding:100px 120px;'>\
<h3>��������</h3>\
<p> <br></p>\
<p> <br></p>\
</p>\
<form name=\"addNum\" id=\"addNum\" method=\"GET\" target=\"iframe\" action=\"Taskctrl.js\">\
<p style=\"font-size: 22px;\"><lable> ����ģʽ:</label>\
<select id=\"txtMODE\" style=\"width:150px\" name='mode'><option selected value='1'>MODBUS RTU</option>\
<option value='2'>MODBUS TCP/IP</option><option  value='3'>MODBUS UDP/IP</option></select>\
<p style=\"font-size: 22px;margin-top:-35px;margin-left:300px;\"><lable> ����:</label>\
<select id=\"txtUSART\" style=\"width:150px\" name='usart'><option value='1'>RS485_1</option>\
<option selected value='2'>RS485_2</option><option value='3'>RS232</option></select>\
<p> <br></p>\
<p> <br></p>\
<p><label for='txtIp'>�ӻ�ID:</label><input type='text' id='txtSid' name='sid' ></p>\
<p style=\"margin-top:-35px;margin-left:300px;\"><label for='txtRPORT'>������:</label><input type='text' id='txtFC' name='fc' size='16' >\
<p style=\"margin-top:-35px;margin-left:600px;\"><label for='txtRPORT'>��ʼ��ַ:</label><input type='text' id='txtADDR' name='addr' size='16' >\
<p style=\"margin-top:-35px;margin-left:900px;\"><label for='txtRPORT'>��ȡ����:</label><input type='text' id='txtNUM' name='number' size='16' >\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <br></p>\
<p> <input style=\"width:150px;height:50px;border-radius: 10px;margin-left:600px;\"  id=\"sendmodbus\" type ='submit' value = '���'></p>\
</form>\
<iframe id=\"iframe\" name=\"iframe\" style=\"display:none;\"></iframe>\
<p> <br></p>\
<p> <br></p>\
<div style=\"width:1400px;height:400px;overflow-y:scroll;overflow-x:none;\">\
<table id=\"task\">\
<thead>\
<tr>\
<th id=\"td_id\">���</th>\
<th id=\"td_addr\">�ӻ�ID</th>\
<th id=\"td_pos\">��ȡ��ַ</th>\
<th id=\"td_value\">ֵ</th>\
<th id=\"td_select\">����</th>\
</tr>\
</thead>\
</table>\
</div>\
</div>\
</div>\
</div>\
</div>\
</div>\
<div class=\"ground\" id=\"Ground\">\
<div class=\"ground1\">\
<div class=\"headline\"><h2 id=\"Headline\">�༭</h2></div>\
<div style=\"top: 80px;\" class=\"mybox\"><label style=\"font-family: ����_GB2312;\">���:</label><input type='text' disabled='disabled' value = '1' ></div>\
<div style=\"top: 160px;\" class=\"mybox\"><label style=\"font-family: ����_GB2312;\">������:</label><input type='text'  value = '' ></div>\
<div style=\"top: 240px;\" class=\"mybox\"><label style=\"font-family: ����_GB2312;\">��ʼ��ַ:</label><input type='text'  value = '' ></div>\
<div style=\"top: 320px;\" class=\"mybox\"><label style=\"font-family: ����_GB2312;\">��ȡ����:</label><input type='text'  value = '' ></div>\
<div class=\"button1\"><button class=\"yes\" onclick=\"conceal()\" id=\"Button1\">ȷ��</button><button class=\"no\" onclick=\"conceal()\" id=\"Button2\">ȡ��</button></div>\
</div>\
</div>\
</body>\
</html>\
<script type='text/javascript' src='Taskctrl.js'></script>\
<script>\
window.id = 48;\
window.addr = 2;\
window.pos = 3;\
window.value = 4;\
var btn_add = document.getElementById(\"sendmodbus\");\
btn_add.onclick = function() {\
var tb = document.getElementById(\"task\");\
var tg = document.createElement(\"tbody\");\
var tt = document.createElement(\"tr\");\
var td1 = document.createElement(\"td\");\
var td2 = document.createElement(\"td\");\
var td3 = document.createElement(\"td\");\
var td5 = document.createElement(\"td\");\
var td4 = document.createElement(\"td\");\
var pa = document.createElement(\"td\");\
var pb = document.createElement(\"td\");\
var bt1 = document.createElement(\"button\");\
var bt2 = document.createElement(\"button\");\
var sp1 = document.createElement(\"span\");\
var sp2 = document.createElement(\"span\");\
window.addr = document.getElementById(\"txtSid\").value;\
window.pos = document.getElementById(\"txtADDR\").value;\
pa.setAttribute(\"style\", \"width: 550px;\");\
bt1.setAttribute(\"style\", \"margin-left: -200px;\");\
bt1.setAttribute(\"class\", \"niceButton5\");\
bt1.setAttribute(\"onclick\", \"Edittr(this)\");\
bt1.setAttribute(\"href\", \"javascript:void(0)\");\
sp1.innerHTML = \"�༭\";\
bt1.appendChild(sp1);\
bt2.setAttribute(\"style\", \"margin-right: -200px;\");\
bt2.setAttribute(\"class\", \"niceButton5\");\
bt2.setAttribute(\"onclick\", \"deleteTr(this)\");\
bt2.setAttribute(\"href\", \"javascript:void(0)\");\
sp2.innerHTML = \"ɾ��\";\
bt2.appendChild(sp2);\
pa.appendChild(bt1);\
pa.appendChild(bt2);\
td1.innerHTML = window.id;\
window.id = window.id+1;\
td2.innerHTML = window.addr;\
td3.innerHTML = window.pos;\
td5.innerHTML = window.value;\
tt.appendChild(td1);\
tt.appendChild(td2);\
tt.appendChild(td3);\
tt.appendChild(td5);\
tt.appendChild(pa);\
tg.appendChild(tt);\
tb.appendChild(tg);\
};\
function deleteTr(object) {\
var script = document.createElement(\"script\");\
script.setAttribute(\"type\",\"text/javascript\");\
script.src = \"/Deletetr.js\";\
document.getElementsByTagName(\"head\")[0].appendChild(script);\
window.id = window.id-1;\
var table = object.parentNode.parentNode.parentNode;\
var tr = object.parentNode.parentNode;\
table.removeChild(tr);\
}\
function Edittr(){\
document.getElementById(\"Ground\").style.display=\"block\";\
}\
function conceal(){\
document.getElementById(\"Ground\").style.display=\"none\";\
}\
</script>"\





#define Update_html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"???,???\">\
<meta name=\"description\" content="">\
<style type=\"text/css\">\
* {\
margin: 0;\
padding: 0;\
}\
body {\
font-size: 12px;\
font-family: \"????\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat 0 -51px;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat -386px -15px;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
<script>\
function $(id) { return document.getElementById(id); }\
function settingsUpdateCallback(o) {\
document.getElementById(\"software_version_value\").innerHTML = o.Version;\
var dev_type_map = new Map(\
[\
[1,\"������ܰ�\"]\
]\
);\
document.getElementById(\"board_type_value\").innerHTML = dev_type_map.get(o.Type);\
}\
</script>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li >\
<a href=\"XT_Main_Weight\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li>\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li >\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<div class=\"h_user\">�������ص�ز���ƽ̨</div>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û���LZH , ��ݣ�ϵͳ����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>����ǰ����λ�ã���ҳ > ��̨����</p>\
</div>\
<div id='main'>\
<div style='background:snow; display:block;padding:100px 120px;'>\
<div style=\"text-align: center;\">\
<h1>XinTong DTU Firmware Manager</h1>\
<br></br>\
<form target=\"_blank\" method=\"post\" enctype=\"multipart/form-data\" action=\"upload.cgi\">\
<input id=\"files\" name=\"file\" type=\"file\" />\
<input name=\"submit\" type=\"submit\" value=\"�ύ\" />\
</form>\
<br></br>\
<label style=\"margin-left: -190px;\" id=\"software_version_label\"> �Ӱ�����汾��: </label>\
<label id=\"software_version_value\">  </label>\
<br></br>\
<label style=\"margin-left: -190px;\" id=\"board_type_label\"> �Ӱ�����: </label>\
<label id=\"board_type_value\"> </label>\
<br></br>\
<div class=\"row\">\
<p> stm32 id :\
<input type=\"text\" id=\"stm32IdText\" value=\"0\" />\
&nbsp\
<button class=\"button is-primary\" id=\"updateStm32Btn\" onclick=\"updateStm32()\"> ��ʼ���� </button>\
<button class=\"button is-primary\" id=\"getStm32SoftwareVersion\" onclick=\"getStm32SoftwareVersion()\"> ��ȡ�Ӱ�汾�� </button>\
<br></br>\
</p>\
</div>\
<br></br>\
<nav class=\"level\">\
<div class=\"level-left\">\
<label style=\"margin-left: auto;\" >���������� : </label>\
&nbsp;&nbsp;&nbsp;\
<progress id=\"progress_bar\" style=\"width: 200px;\" class=\"progress is-primary\" value=\"0\"\
max=\"100\"></progress>\
<label  id=\"update_size\">��������:</label>\
</div>\
</nav>\
</div>\
</div>\
</div>\
</div>\
</body>\
</html>\
<script type='text/javascript' src='Upadate.js'></script>\
<script>\
function updateStm32() {\
var obj = new Object();\
obj.topic = \"updateStm32\";\
obj.board_index = document.getElementById(\"stm32IdText\").value;\
obj.hex_name = document.getElementById('files').files[0].name;\
var msg = JSON.stringify(obj);\
console.log(msg);\
}\
</script>"


#define UPLOADDONE_HTML     \
"<!DOCTYPE HTML PUBLIC '-//W3C//DTD HTML 4.01 Transitional//EN'>\r\n"    \
"<html>     \r\n"    \
"  <head>       \r\n"    \
"    <meta http-equiv='content-type' content='text/html; charset=windows-1250'>       \r\n"    \
"    <title>STM32 IAP using HTTP     \r\n"    \
"    </title>     \r\n"    \
"  </head>     \r\n"    \
"  <body>  File Upload Done!      \r\n"    \
"    <br>        \r\n"    \
"    <form action ='/resetmcu.cgi' enctype='text/plain' method='get'>    \r\n"    \
"      <input type='submit' value='Reset MCU'>\r\n"    \
"    </form>  \r\n"    \
"  </body>\r\n"    \
"</html>"



#define Debug_html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:100px;font-size: 13px;}\
select{margin-left:10px;width:130px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
table{\
width: 100%;\
border-collapse: collapse;\
}\
table caption{\
font-size: 2em;\
font-weight: bold;\
margin: 1em 0;\
}\
th,td{\
border: 1px solid #999;\
text-align: center;\
padding: 20px 0;\
}\
table thead tr{\
background-color: #008c8c;\
color: #eee;\
}\
table tbody tr:nth-child(odd){\
background-color: #eee;\
}\
table tbody tr:hover{\
background-color: #ccc;\
}\
table tbody tr td:first-child{\
color: #f40;\
}\
table tfoot tr td{\
text-align: right;\
padding-right: 20px;\
}\
.mybox{\
margin: auto;\
position: absolute;\
left: 100px;\
right: 0;\
bottom: 0;\
}\
.cmn-toggle {\
position: absolute;\
margin-left: -9999px;\
visibility: hidden;\
}\
.cmn-toggle + label {\
display: block;\
position: relative;\
cursor: pointer;\
outline: none;\
user-select: none;\
}\
input.cmn-toggle-round + label {\
padding: 2px;\
width: 60px;\
height: 30px;\
background-color: #dddddd;\
border-radius: 60px;\
}\
input.cmn-toggle-round + label:before,\
input.cmn-toggle-round + label:after {\
display: block;\
position: absolute;\
top: 1px;\
left: 1px;\
bottom: 1px;\
content: \"\";\
}\
input.cmn-toggle-round + label:before {\
right: 1px;\
background-color: #f1f1f1;\
border-radius: 60px;\
transition: background 0.4s;\
}\
input.cmn-toggle-round + label:after {\
width: 30px;\
background-color: #fff;\
border-radius: 100%;\
box-shadow: 0 2px 5px rgba(0, 0, 0, 0.3);\
transition: margin 0.4s;\
}\
input.cmn-toggle-round:checked + label:before {\
background-color: #8ce196;\
}\
input.cmn-toggle-round:checked + label:after {\
margin-left: 30px;\
}\
input{\
border:none;\
width:200px;height:80px;\
box-radius:25%;\
outline:medium;\
text-align:center;\
}\
.niceButton5 {\
display: inline-block;\
border-radius: 15px;\
background-color: #7a55e0;\
border: none;\
color: #ffff;\
text-align: center;\
font-size: 10px;\
font-weight: 200;\
padding: 9px;\
width: 80px;\
height: 30px;\
transition: all 0.5s;\
cursor: pointer;\
margin: 5px;\
vertical-align: middle;\
margin-left: 10px;\
}\
.niceButton5 span {\
cursor: pointer;\
display: inline-block;\
position: relative;\
transition: 0.5s;\
}\
.niceButton5 span::after {\
content: \">>\";\
position: absolute;\
opacity: 0;\
top: 0;\
right: -30px;\
transition: 0.5s;\
margin-top: 1px;\
}\
.niceButton5:hover span {\
padding-right: 22px;\
}\
.niceButton5:hover span::after {\
opacity: 1;\
right: 0;\
}\
.wrapper .input-data{\
width: 40%;\
height: 40px;\
position: relative;\
}\
.wrapper .input-data input{\
width: 40%;\
height: 100%;\
border: none;\
border-bottom: 2px solid silver;\
font-size: 17px;\
}\
.input-data input:focus ~ label,\
.input-data input:valid ~ label{\
transform: translateY(-30px);\
font-size: 13px;\
color: #314bce;\
}\
.wrapper .input-data label{\
position: absolute;\
bottom: 10px;\
left: 0;\
color: grey;\
pointer-events: none;\
transition: all 0.3s ease;\
}\
.wrapper .input-data .underline{\
position: absolute;\
bottom: 0px;\
height: 1px;\
width: 40%;\
}\
.input-data .underline:before{\
position: absolute;\
content: \"\";\
height: 100%;\
width: 100%;\
background: #5f77ec;\
transform: scaleX(0);\
transition:transform 0.3s ease;\
}\
.input-data input:focus ~ .underline:before,\
.input-data input:valid ~ .underline:before{\
transform: scaleX(1);\
}\
.ground{\
display: none;\
box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);\
width: 400px;\
height: 400px;\
border-radius: 20px;\
border: 2px solid #fff;\
background: #fff;\
margin: auto;\
position: absolute;\
top: -200px;\
left: 0;\
right: 0;\
bottom: 0;\
}\
.ground1{\
position: relative;\
}\
.headline{\
margin: auto;\
position: absolute;\
top: 10px;\
left: 175px;\
right: 0;\
bottom: 0;\
}\
.text{\
margin: auto;\
position: absolute;\
top: 110px;\
left: 50px;\
right: 0;\
bottom: 0;\
}\
.yes,.no{\
border: 2px solid #87cefa;\
background: #87cefa;\
border-radius: 11px;\
width: 65px;\
height: 38px;\
font-size: 17px;\
}\
.yes{\
margin: auto;\
position: absolute;\
top: 700px;\
left: -80px;\
right: 0;\
bottom: 0;\
}\
.no{\
margin: auto;\
position: absolute;\
top: 700px;\
left: 80px;\
right: 0;\
bottom: 0;\
}\
* {\
margin: 0;\
padding: 0;\
}\
body {\
font-size: 12px;\
font-family: \"΢���ź�\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat 0 -51px;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat -386px -15px;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a:hover {\
background-color: #2f3437;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_see {\
background-position: -359px -45px;\
background-color: #6297bc;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_edit {\
background-position: -379px -47px;\
background-color: #27a9e3;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_save {\
background-position: -398px -47px;\
background-color: #28b779;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action .a_del {\
background-position: -417px -48px;\
background-color: #ff912f;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
</style>\
<script>\
</script>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li >\
<a href=\"XT_Main_Weight\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li>\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li>\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û���LZH , ��ݣ�ϵͳ����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>����ǰ����λ�ã���ҳ > ��̨����</p>\
</div>\
<div id='main'>\
<div style='background:white; display:block;padding:100px 120px;'>\
<h3>��̫������</h3> \
<br></br>\
<div class=\"wrapper\">\
<div class=\"input-data\">\
<input type=\"text\" required=\"\" />\
<div class=\"underline\"></div>\
<label>�������������</label>\
</div>\
</div>\
<div style=\"margin-left: 230px; margin-top: -30px;\">\
<button class=\"niceButton5\"><span>����</span></button>\
</div>\
<br></br>\
<h2>����:</h2>\
<div style=\"margin-top: -30px; margin-left: 50px;\" class=\"switch\">\
<input id=\"cmn-toggle-1\" class=\"cmn-toggle cmn-toggle-round\" type=\"checkbox\">\
<label for=\"cmn-toggle-1\"></label>\
</div>\
<details style=\"margin-top: -25px; margin-left: 130px;\">\
<summary>Details</summary>\
���Կ��ش򿪺�ֹͣ���������ϱ�\
</details>\
<br></br>\
<br></br>\
<br></br>\
<h3>4G����</h3>\
<br></br>\
<div class=\"wrapper\">\
<div class=\"input-data\">\
<input type=\"text\" required=\"\" />\
<div class=\"underline\"></div>\
<label>�������������</label>\
</div>\
</div>\
<div style=\"margin-left: 230px; margin-top: -30px;\">\
<button class=\"niceButton5\"><span>����</span></button>\
</div>\
<br></br>\
<h2>����:</h2>\
<div style=\"margin-top: -30px; margin-left: 50px;\" class=\"switch\">\
<input id=\"cmn-toggle-2\" class=\"cmn-toggle cmn-toggle-round\" type=\"checkbox\">\
<label for=\"cmn-toggle-2\"></label>\
</div>\
<details style=\"margin-top: -25px; margin-left: 130px;\">\
<summary>Details</summary>\
���Կ��ش򿪺�ֹͣ���������ϱ�\
</details>\
</div>\
<div style=\"margin-left: 680px; margin-top: -480px;\">\
<h2>������Ϣ��</h2>\
<textarea readonly style=\"overflow-y:visible; border:0;border-radius:5px;background-color:rgba(241,241,241,.98);width: 800px;height: 400px;padding: 10px;resize: none;\"></textarea>\
</div>\
</div>\
</div>\
</div>\
</body>\
</html>\
<script>\
</script>\
"

#define Account_html "\
<!doctype html>\
<html>\
<head>\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=GB2312\">\
<title></title>\
<meta name=\"Keywords\" content=\"�ؼ���,�ؼ���\">\
<meta name=\"description\" content=\"\">\
<style type=\"text/css\">\
body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
#main {margin-right:auto;margin-left:auto;margin-top:0px;}\
label{display:inline-block;width:130px;font-size: 22px;}\
select{margin-left:50px;width:100px;height:30px;border-radius: 10px; font-size: 15px;text-align:center;}\
#main h3{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-60px;}\
#main h4{color:#66b3ff; text-decoration:underline;font-size: 25px;margin-top:-30px;margin-left: 600px;}\
* {\
margin: 0;\
padding: 0;\
}\
* {\
margin: 0;\
padding: 0\
}\
.saveButton{\
margin-left: 25px;\
background: rgb(120, 196, 105);\
height: 30px;\
width: 50px;\
border-radius: 3px;\
font-family: \"����ϸ��\";\
}\
.closeButton{\
margin-left: 25px;\
background: rgb(238, 56, 32);\
height: 30px;\
width: 50px;\
border-radius: 3px;\
font-family: \"����ϸ��\";\
}\
.checkBox {\
position: relative;\
width: 0.48rem;\
height: 0.48rem;\
background: #ffffff;\
}\
.checkBox label {\
cursor: pointer;\
position: absolute;\
width: 0.48rem;\
height: 0.48rem;\
top:0;\
left: 0;\
background: #ffffff;\
border: 0.01rem solid #c2c2c2;\
border-radius: 0.04rem;\
}\
.checkBox label:after {\
opacity: 0.5;\
content: '';\
position: absolute;\
width: 0.3rem;\
height: 0.2rem;\
background: transparent;\
top: 0.09rem;\
left: 0.07rem;\
border: 0.05rem solid #2381D8;\
border-top: none;\
border-right: none;\
-webkit-transform: rotate(-45deg);\
-moz-transform: rotate(-45deg);\
-o-transform: rotate(-45deg);\
-ms-transform: rotate(-45deg);\
transform: rotate(-45deg);\
}\
.checkBox label:hover::after {\
opacity: 0;\
}\
.checkBox input[type=checkbox]:checked + label:after {\
opacity: 1;\
}\
.xtspan{\
font-size: 15px;\
font-family: \"����ϸ��\";\
}\
.from {\
overflow: hidden;\
position: relative;\
}\
.bgc {\
width: 100%;\
}\
.xtbutton{\
margin-left: 10px;\
background: transparent;\
border-width: 0px; \
outline: none;\
cursor: pointer;\
font-size: 18px;\
}\
.submit {\
z-index: 9;\
left: 0;\
top: 0;\
right: 0;\
bottom: 0;\
margin: auto;\
margin-top: 20px;\
margin-left: 150px;\
width: 300px;\
height: 500px;\
background: rgba(216, 205, 205, 0.2);\
border-radius: 10px;\
color: #0e0c0c;\
display: flex;\
flex-direction: column;\
}\
.submit2{\
z-index: 9;\
left: 0;\
top: 0;\
right: 0;\
bottom: 0;\
margin: auto;\
margin-top: -495px;\
margin-left: 480px;\
width: 1100px;\
height: 470px;\
background: rgba(216, 205, 205, 0.2);\
border-radius: 10px;\
color: #0e0c0c;\
display: flex;\
flex-direction: column;\
}\
.form_title {\
text-align: center;\
margin-top: 30px;\
font-size: 18px;\
font-family: \"����ϸ��\";\
}\
.form_input {\
padding: 0 30px;\
box-sizing: border-box;\
display: flex;\
margin-top: 20px;\
}\
.inputs {\
height: 35px;\
width: 1000px;\
border-radius: 5px;\
background-color: #eee;\
color: #666;\
padding-left: 20px;\
}\
.form_input span {\
width: 85px;\
align-self: center;\
}\
.btn_submit {\
align-self: center;\
}\
.btn {\
border: none;\
width: 80px;\
height: 40px;\
color: #fff;\
border-radius: 5px;\
background: #999;\
margin-top: 40px;\
}\
.btn:hover {\
background: #666;\
}\
.back {\
margin-left: 10px;\
}\
.home_href {\
border: none;\
width: 80px;\
height: 40px;\
color: #fff;\
border-radius: 5px;\
background: #FFD204;\
}\
.xtText{\
margin-left: 10px;\
font-size: 15px;\
font-family: \"΢���ź�\";\
}\
.xtText input{\
margin-left: 30px;\
background-color:transparent;\
border:0;\
text-align: right;\
}\
#wrapper{\
width: 1200px;\
height: 500px;\
}\
body {\
font-size: 12px;\
font-family: \"΢���ź�\";\
color: #666;\
}\
a {\
text-decoration: none;\
}\
ul li {\
list-style: none;\
}\
.tz_content {\
width: 100%;\
background: #282828;\
}\
.tz_content .t_left {\
width: 200px;\
height: 800px;\
background: #282828;\
position: fixed;\
left: 0;\
top: 0;\
z-index: 2;\
}\
.tz_content .t_left .l_logo {\
width: 100%;\
height: 108px;\
border-bottom: 1px solid #000000;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav {\
width: 100%;\
border-bottom: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li {\
border-bottom: 1px solid #000000;\
line-height: 52px;\
border-top: 1px solid #414141;\
}\
.tz_content .t_left .l_nav ul li a {\
display: block;\
padding-left: 30px;\
}\
.tz_content .t_left .l_nav ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul .active a {\
background: #28b779;\
}\
.tz_content .t_left .l_nav ul li a i {\
width: 16px;\
height: 16px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-top: 20px;\
}\
.tz_content .t_left .l_nav ul li a .icon_1 {\
background-position: -233px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_2 {\
background-position: -254px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_3 {\
background-position: -211px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_4 {\
background-position: -274px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_5 {\
background-position: -295px -52px;\
}\
.tz_content .t_left .l_nav ul li a .icon_6 {\
background-position: -315px -52px;\
width: 19px;\
height: 6px;\
margin-top: 24px;\
}\
.tz_content .t_left .l_nav ul li a span {\
font-size: 14px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header {\
width: 100%;\
height: 56px;\
background: #2f3437;\
position: relative;\
z-index: 1;\
}\
.tz_content .t_header .h_nav {\
height: 56px;\
margin-left: 200px;\
float: left;\
}\
.tz_content .t_header .h_nav ul li {\
float: left;\
width: 200px;\
height: 56px;\
border-left: 2px solid #414141;\
border-right: 2px solid #000;\
}\
.tz_content .t_header .h_nav ul li a {\
display: block;\
color: #838383;\
text-align: center;\
padding-top: 8px;\
}\
.tz_content .t_header .h_nav ul li a:hover {\
font-size: 100px;\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a i {\
display: block;\
width: 18px;\
height: 17px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
margin: 3px auto;\
}\
.tz_content .t_header .h_nav ul li .h_sel {\
color: #fff;\
}\
.tz_content .t_header .h_nav ul li a .h_icon1 {\
background-position: 0 -50px;\
}\
.tz_content .t_header .h_info {\
height: 56px;\
position: absolute;\
top: 0;\
right: 10px;\
}\
.tz_content .t_header .h_info .h_user {\
line-height: 56px;\
color: #fff;\
float: left;\
}\
.tz_content .t_header .h_info .h_out {\
width: 65px;\
height: 30px;\
background: #28b779;\
margin: 13px 5px 0 10px;\
float: right;\
}\
.tz_content .t_header .h_info .h_out a {\
display: block;\
line-height: 30px;\
color: #fff;\
padding-left: 10px;\
}\
.tz_content .t_header .h_info .h_out a span {\
float: left;\
}\
.tz_content .t_header .h_info .h_out a i {\
width: 14px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat 0 -51px;\
float: left;\
margin: 6px 8px;\
}\
.tz_content .t_right {\
height: 1500px;\
background: #f3f4f5;\
margin-left: 200px;\
}\
.tz_content .t_right .r_location {\
height: 51px;\
background: #e5e5e5;\
border-bottom: 1px solid #ccc;\
line-height: 51px;\
}\
.tz_content .t_right .r_location i {\
width: 14px;\
height: 18px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
background-position: -16px -51px;\
float: left;\
margin: 16px 20px 0 20px;\
}\
.tz_content .t_right .r_message .m_list {\
height: 0px;\
float: left;\
margin-left: 1%;\
margin-top: 0px;\
}\
.tz_content .t_right .r_message .m_1 {\
width: 22%;\
background: #27a9e3;\
}\
.tz_content .t_right .r_message .m_1 .m_pic {\
background-position: 0 0px;\
}\
.clear {\
clear: both;\
}\
.tz_content .t_right .r_table {\
border: 1px solid #ccc;\
margin: 0 1% 0 1%;\
background: #fff;\
margin-top: 20px;\
padding-bottom: 10px;\
}\
.tz_content .t_right .r_table .r_title {\
width: 100%;\
height: 40px;\
background: #eee;\
border-bottom: 1px solid #ccc;\
}\
.tz_content .t_right .r_table .r_title i {\
width: 16px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat -386px -15px;\
float: left;\
margin: 12px;\
}\
.tz_content .t_right .r_table .r_title p {\
height: 40px;\
line-height: 40px;\
border-left: 1px solid #ccc;\
float: left;\
padding-left: 5px;\
color: #000;\
}\
.tz_content .t_right .r_table .r_label {\
width: 80%;\
height: 100px;\
float: left;\
}\
.tz_content .t_right .r_table .r_label ul li {\
list-style: none;\
float: left;\
background: #999;\
margin: 10px 10px 0 10px;\
}\
.tz_content .t_right .r_table .r_label ul li a {\
display: block;\
padding: 8px 20px;\
color: #fff;\
}\
.tz_content .t_right .r_table .r_label ul li a:hover {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul .select a {\
background: #28b779;\
}\
.tz_content .t_right .r_table .r_label ul li a i {\
width: 15px;\
height: 14px;\
display: block;\
background: url(\"picture/ht_icon.png\") no-repeat;\
float: left;\
margin-right: 10px;\
}\
.tz_content .t_right .r_table .r_search {\
width: 19%;\
height: 30px;\
float: left;\
padding-top: 10px;\
}\
.tz_content .t_right .r_table .r_search .r_text {\
width: 60%;\
height: 28px;\
line-height: 28px;\
border: 1px solid #ddd;\
float: right;\
}\
.tz_content .t_right .r_table .r_search .r_btn {\
width: 20%;\
height: 29px;\
background: #999;\
color: #fff;\
cursor: pointer;\
border: 0;\
float: right;\
}\
.tz_content .t_right .r_table .r_table_list {\
width: 100%;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab {\
border-collapse: collapse;\
width: 98%;\
text-align: center;\
margin: 0 1%;\
}\
.tz_content .t_right .r_table .r_table_list tr th {\
line-height: 40px;\
background: #eee;\
}\
.tz_content .t_right .r_table .r_table_list tr td {\
border: 1px solid #ddd;\
line-height: 40px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab thead {\
border: 1px solid #ddd;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover {\
background: #EAEAEA;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr:hover .t_action {\
display: block;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action {\
width: 108px;\
height: 24px;\
margin: 0 auto;\
display: none;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr .t_td {\
width: 120px;\
}\
.tz_content .t_right .r_table .r_table_list .t_tab tbody tr td .t_action a {\
width: 24px;\
height: 24px;\
display: block;\
float: left;\
margin-right: 2px;\
background: url(\"picture/ht_icon.png\") no-repeat;\
}\
@media screen and (max-width:1024px) {\
.tz_content .t_left {\
width: 50px;\
}\
.tz_content .t_left .l_logo {\
height: 54px;\
background: url(\"picture/logo1.png\") no-repeat center;\
}\
.tz_content .t_left .l_nav ul li a {\
padding-left: 16px;\
height: 52px;\
}\
.tz_content .t_left .l_nav ul li a span {\
display: none;\
}\
.tz_content .t_header .h_info .h_user {\
display: none;\
}\
.tz_content .t_right {\
margin-left: 0;\
}\
.tz_content .t_right .r_location {\
margin-left: 50px;\
}\
.tz_content .t_right .r_message {\
margin-left: 50px;\
}\
.tz_content .t_right .r_table {\
margin-left: 60px;\
}\
}\
\
</style>\
</head>\
<body>\
<div class=\"tz_content\">\
<div class=\"t_left\">\
<div class=\"l_logo\"></div>\
<div class=\"l_nav\">\
<ul>\
<li>\
<a href=\"\">\
<i class=\"icon_1\"></i>\
<span>��ҳ</span>\
</a>\
</li>\
<li >\
<a href=\"Net_Config.html\">\
<i class=\"icon_1\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Usart_Config.html\">\
<i class=\"icon_2\"></i>\
<span>��������</span>\
</a>\
</li>\
<li>\
<a href=\"Debug.html\">\
<i class=\"icon_3\"></i>\
<span>���ߵ���</span>\
</a>\
</li>\
<li>\
<a href=\"Modbus_Config.html\">\
<i class=\"icon_4\"></i>\
<span>��������</span>\
</a>\
</li>\
<li class=\"active\">\
<a href=\"Account.html\">\
<i class=\"icon_5\"></i>\
<span>�˺Ź���</span>\
</a>\
</li>\
<li>\
<a href=\"Update.html\">\
<i class=\"icon_6\"></i>\
<span>�̼�����</span>\
</a>\
</li>\
</ul>\
</div>\
</div>\
<div class=\"t_header\">\
<div class=\"h_nav\">\
<ul>\
<li>\
<a href=\"#\" class=\"h_sel\">\
<i class=\"h_icon1\"></i>\
<span>�������ص�ز���ƽ̨</span>\
</a>\
</li>\
</ul>\
</div>\
<div class=\"h_info\">\
<div class=\"h_user\">��ǰ�û�:LZH , ��ݣ�ϵͳ����Ա</div>\
<div class=\"h_out\">\
<a href=\"#\">\
<span>�˳�</span>\
<i></i>\
</a>\
</div>\
</div>\
</div>\
<div class=\"t_right\">\
<div class=\"r_location\">\
<i></i>\
<p>����ǰ����λ�ã���ҳ > ��̨����</p>\
</div>\
<div id='main'>\
<h3 style=\"margin-top: 70px; margin-left: 150px;\">�˺Ź���</h3>\
<div class=\"submit\">\
<span class=\"form_title\">������Ϣ</span>\
<br></br>\
<div style=\"border:1px solid #474343\"></div>\
<p class=\"form_title\" style=\"font-size: 15px;\" onclick=\"\">����ͷ��</p>\
<br></br>\
<div style=\"border:1px solid #CCC\"></div>\
<br></br>\
<p class=\"xtText\">�û�����:<input disabled  type=\"text\" value=\"LZH\"></p>\
<br></br>\
<div style=\"border:1px solid #CCC\"></div>\
<br></br>\
<p class=\"xtText\">�û�����:<input disabled  type=\"text\" value=\"1120584450@qq.com\"></p>\
<br></br>\
<div style=\"border:1px solid #CCC\"></div>\
<br></br>\
<p class=\"xtText\">������ɫ:<input disabled  type=\"text\" value=\"����Ա\"></p>\
<br></br>\
<div style=\"border:1px solid #CCC\"></div>\
<br></br>\
<p class=\"xtText\">��������:<input disabled  type=\"text\" value=\"2024.3.13\"></p>\
<br></br>\
</div>\
<div class=\"submit2\" id=\"mysubmit\">\
<span style=\"font-size: 18px; font-family: ����ϸ��; margin-left: 20px; margin-top: 25px;\" >��������</span>\
<br></br>\
<div style=\"border:1px solid #474343\"></div>\
<br></br>\
<div><button class=\"xtbutton\" onclick=\"a()\" id=\"b1\" style=\"color:#1caa2f;\">������Ϣ</button><button class=\"xtbutton\" onclick=\"b()\" id=\"b2\">�޸�����</button></div>\
<div id=\"database\">\
<br></br>\
<div class=\"form_input\">\
<span class=\"xtspan\">�û����ƣ�</span>\
<input class=\"inputs\" type=\"text\" value=\"LZH\">\
</div>\
<div class=\"form_input\">\
<span class=\"xtspan\">�û����䣺</span>\
<input class=\"inputs\" type=\"text\" value=\"1120584450@qq.com\">\
</div>\
<div class=\"form_input\">\
<span class=\"xtspan\">�ֻ�����:</span>\
<input class=\"inputs\" type=\"text\" value=\"1234567890\">\
</div>\
<div class=\"form_input\">\
<span class=\"xtspan\">�Ա�:</span>\
<input style=\"margin-top: 5px;\" class=\"sure\" type=\"checkbox\" name=\"\" value=\"1\" id=\"checkBoxInput\">\
<label for=\"checkBoxInput\"></label>\
<p style=\"margin-top: 4px; margin-left: -120px;\">��</p>\
<input style=\"margin-top: 5px; margin-left: 10px;\" class=\"sure\" type=\"checkbox\" name=\"\" value=\"1\" id=\"checkBoxInput\">\
<label for=\"checkBoxInput\"></label>\
<p style=\"margin-top: 4px; margin-left: -120px;\">Ů</p>\
</div>\
<br></br>\
<button class=\"saveButton\">����</button>\
<button class=\"closeButton\">ȡ��</button>\
</div>\
</div>\
</div>\
</div>\
</body>\
<script>\
function a(){\
document.getElementById(\"database\").innerHTML=\"\";\
document.getElementById(\"b1\").style.color=\"#1caa2f\";\
document.getElementById(\"b2\").style.color=\"black\";\
var id = document.getElementById(\"database\");\
var div1 = document.createElement(\"div\");\
var br1 = document.createElement(\"br\");\
var br2 = document.createElement(\"br\");\
var br3 = document.createElement(\"br\");\
var br4 = document.createElement(\"br\");\
var button1 = document.createElement(\"button\");\
var button2 = document.createElement(\"button\");\
var div2 = document.createElement(\"div\");\
var span1 = document.createElement(\"span\");\
var input1 = document.createElement(\"input\");\
var div3 = document.createElement(\"div\");\
var span2 = document.createElement(\"span\");\
var input2 = document.createElement(\"input\");\
var div4 = document.createElement(\"div\");\
var span3 = document.createElement(\"span\");\
var input3 = document.createElement(\"input\");\
var div5 = document.createElement(\"div\");\
var span4 = document.createElement(\"span\");\
var input4 = document.createElement(\"input\");\
var label1 = document.createElement(\"label\");\
var p1 = document.createElement(\"p\");\
var input5 = document.createElement(\"input\");\
var label2 = document.createElement(\"label\");\
var p2 = document.createElement(\"p\");\
div2.setAttribute(\"class\",\"form_input\");\
span1.setAttribute(\"class\",\"xtspan\");\
span1.innerHTML=\"�û�����\"\
button1.setAttribute(\"class\",\"saveButton\");\
button1.innerHTML=\"����\";\
button2.setAttribute(\"class\",\"closeButton\");\
button2.innerHTML=\"ȡ��\";\
div3.setAttribute(\"class\",\"form_input\");\
span2.setAttribute(\"class\",\"xtspan\");\
span2.innerHTML=\"�û�����\";\
div4.setAttribute(\"class\",\"form_input\");\
span3.setAttribute(\"class\",\"xtspan\");\
span3.innerHTML=\"�ֻ�����\";\
input1.setAttribute(\"class\",\"inputs\");\
input1.setAttribute(\"type\",\"text\");\
input1.setAttribute(\"value\",\"LZH\");\
input2.setAttribute(\"class\",\"inputs\");\
input2.setAttribute(\"type\",\"text\");\
input2.setAttribute(\"value\",\"1120584450@qq.com\");\
div5.setAttribute(\"class\",\"form_input\");\
span4.innerHTML=\"�Ա�\";\
input4.setAttribute(\"style\",\"margin-top: 5px;\");\
input4.setAttribute(\"class\",\"sure\");\
input4.setAttribute(\"type\",\"checkbox\");\
input4.setAttribute(\"name\",\"\");\
input4.setAttribute(\"value\",\"1\");\
input4.setAttribute(\"id\",\"checkBoxInput\");\
label1.setAttribute(\"for\",\"checkBoxInput\");\
p1.setAttribute(\"style\",\"margin-top: 4px;margin-left: -120px;\");\
p1.innerHTML=\"��\";\
input5.setAttribute(\"style\",\"margin-top: 5px;margin-left: 10px;\");\
input5.setAttribute(\"class\",\"sure\");\
input5.setAttribute(\"type\",\"checkbox\");\
input5.setAttribute(\"name\",\"\");\
input5.setAttribute(\"value\",\"1\");\
input5.setAttribute(\"id\",\"checkBoxInput\");\
label2.setAttribute(\"for\",\"checkBoxInput\");\
p2.setAttribute(\"style\",\"margin-top: 4px;margin-left: -120px;\");\
p2.innerHTML=\"Ů\";\
input3.setAttribute(\"class\",\"inputs\");\
input3.setAttribute(\"type\",\"text\");\
input3.setAttribute(\"value\",\"1234567890\");\
div2.appendChild(span1);\
div2.appendChild(input1);\
div3.appendChild(span2);\
div3.appendChild(input2);\
div4.appendChild(span3);\
div4.appendChild(input3);\
div5.appendChild(span4);\
div5.appendChild(input4);\
div5.appendChild(label1);\
div5.appendChild(p1);\
div5.appendChild(input5);\
div5.appendChild(label2);\
div5.appendChild(p2);\
div1.appendChild(br1);\
div1.appendChild(br4);\
div1.appendChild(div2);\
div1.appendChild(div3);\
div1.appendChild(div4);\
div1.appendChild(div5);\
div1.appendChild(br2);\
div1.appendChild(br3);\
div1.appendChild(button1);\
div1.appendChild(button2);\
id.appendChild(div1);\
}\
function b(){\
document.getElementById(\"database\").innerHTML=\"\";\
document.getElementById(\"b1\").style.color=\"black\";\
document.getElementById(\"b2\").style.color=\"#1caa2f\";\
var id = document.getElementById(\"database\");\
var div1 = document.createElement(\"div\");\
var br1 = document.createElement(\"br\");\
var br2 = document.createElement(\"br\");\
var br3 = document.createElement(\"br\");\
var br4 = document.createElement(\"br\");\
var button1 = document.createElement(\"button\");\
var button2 = document.createElement(\"button\");\
var div2 = document.createElement(\"div\");\
var span1 = document.createElement(\"span\");\
var input1 = document.createElement(\"input\");\
var div3 = document.createElement(\"div\");\
var span2 = document.createElement(\"span\");\
var input2 = document.createElement(\"input\");\
var div4 = document.createElement(\"div\");\
var span3 = document.createElement(\"span\");\
var input3 = document.createElement(\"input\");\
div2.setAttribute(\"class\",\"form_input\");\
span1.setAttribute(\"class\",\"xtspan\");\
span1.innerHTML=\"������:\";\
button1.setAttribute(\"class\",\"saveButton\");\
button1.innerHTML=\"����\";\
button2.setAttribute(\"class\",\"closeButton\");\
button2.innerHTML=\"ȡ��\";\
div3.setAttribute(\"class\",\"form_input\");\
span2.setAttribute(\"class\",\"xtspan\");\
span2.innerHTML=\"������:\";\
div4.setAttribute(\"class\",\"form_input\");\
span3.setAttribute(\"class\",\"xtspan\");\
span3.innerHTML=\"��������:\";\
input1.setAttribute(\"class\",\"inputs\");\
input1.setAttribute(\"type\",\"text\");\
input1.setAttribute(\"value\",\"\");\
input2.setAttribute(\"class\",\"inputs\");\
input2.setAttribute(\"type\",\"text\");\
input2.setAttribute(\"value\",\"\");\
input3.setAttribute(\"class\",\"inputs\");\
input3.setAttribute(\"type\",\"text\");\
input3.setAttribute(\"value\",\"\");\
div2.appendChild(span1);\
div2.appendChild(input1);\
div3.appendChild(span2);\
div3.appendChild(input2);\
div4.appendChild(span3);\
div4.appendChild(input3);\
div1.appendChild(br1);\
div1.appendChild(br4);\
div1.appendChild(div2);\
div1.appendChild(div3);\
div1.appendChild(div4);\
div1.appendChild(br2);\
div1.appendChild(br3);\
div1.appendChild(button1);\
div1.appendChild(button2);\
id.appendChild(div1);\
}\
</script>\
</html>"





//"\
//<!DOCTYPE html>\
//<html>\
//<head>\
//<meta http-equiv='Content-Type' content='text/html'; charset='GB2312'/>\
//<title>������������ƽ̨</title>\
//<style type='text/css'>\
//body {text-align:left; background-color:#c0deed;font-family:Verdana;}\
//#main {margin-right:auto;margin-left:auto;margin-top:30px;}\
//label{display:inline-block;width:150px;}\
//#main h3{color:#66b3ff; text-decoration:underline;}\
//</style>\
//</head>\
//<body>\
//<div id='main'>\
//<div style='background:snow; display:block;padding:10px 20px;'>\
//<h3>setting</h3>\
//<form id='frmSetting' method='POST'action='/allconfig' >\
//<p> <label for='temperature'>�¶�:</label><input type='text' id='temperature' \
//name='temperature' size='16' />  \
//</p>\
//<p><label for='txtIp'>�汾:</label><input type='text' id='txtVer' name='ver' \
//size='16' disabled='disabled' />\
//</p>\
//<p><label for='txtIp'>MAC:</label><input type='text' id='txtMac' name='mac' \
//size='16' disabled='disabled' />\
//</p>\
//<p><label for='txtIp'>IP:</label><input type='text' id='txtIp' name='ip' size='16' \
///>\
//</p>\
//<p><label for='txtSub'>����:</label><input type='text' id='txtSub' name='sub' \
//size='16' />\
//</p>\
//<p><label for='txtGw'>����:</label><input type='text' id='txtGw' name='gw' size='16' \
///>\
//</p>\
//<p><lable>����:</label>\
//<select name='test' id='test'>\
//<option value='1'>��</option>\
//<option selected value='2'>�ر�</option></select>\
//</p>\
//<p><lable>����1͸��:</label><input ���� type='radio' name='serial1' id='serial1on' \
//value='1'>���� <input �ر� type='radio' name='serial1' id='serial1off' \
//value='2'\checked�ر�   \
//</p>\
//<p> <input type ='submit' value = '����'>\
//</p>\
//</form>\
//</div>\
//</div>\
//<div style='margin:5px 5px;'>&copy;Copyright 2023 by LZH\
//</div>\
//</body>\
//</html>\
//"

#endif
