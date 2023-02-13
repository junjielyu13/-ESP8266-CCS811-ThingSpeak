
#include "web.h"

void printWeb(WiFiClient client){
    client.println("
                <!DOCTYPE html>
                <html lang='en'>

                <head>
                    <meta charset='UTF-8'>
                    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
                    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
                    <title>ESP8266_Junjie Web Server</title>
                    <link rel='stylesheet' href='./css/index.css'>
                    <script src='./js/index.js'></script>

                    <style>
                        * {
                            margin: 0;
                        }

                        body {
                            width: 100%;
                            position: relative;
                            font-size: 16;
                            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif
                        }

                        .header {
                            display: flex;
                            flex-direction: row;  
                            justify-content: space-around;
                            align-items: center; 
                            width: 100%;
                            height: 55px;
                            background-color: #2f7eb2;
                        }

                        .header a {
                            display: inline-block;
                            width: 155px;
                            text-decoration: none;
                            text-align: left;
                            font-size: 18px;
                            font-weight: 500;
                            color: #fff;
                        }

                        .mobile-header{
                            position: absolute;
                            display: none;
                            top: 0;
                            right: 10px;
                            width: 55px;
                            height: 55px;
                            cursor: pointer;
                            z-index: 999;
                        }


                        .mobile-icon{
                            width: 80%;
                            height: 20%;
                            display: block;
                            background-color: #fff;
                            border-radius: 25%;
                            margin-top: 10%;
                            margin-bottom: 10%;
                            margin-left: 5%;
                        }

                        .mobile-left{
                            display: none;
                            position: absolute;
                            top: 0;
                            right: 0;
                            height: 100%;
                            width: 80%;
                            background-color: #2f7eb2;
                            opacity: 90%;
                        }

                        .mobile-flow{
                            position: relative;
                            height: 150px;
                            border-bottom: 5px solid rgb(255, 255, 255);
                            margin-left: 10px;
                        }

                        .mobile-flow a{
                            position: absolute;
                            bottom: 0;
                            text-decoration: none;
                            font-size: 32px;
                            font-weight: 600px;
                            color: #fff;
                            margin-left: 20px;
                        }

                        @media screen and (min-width: 401px) {
                            .mobile-header {
                                display: none;
                            }
                            .mobile-left {
                                display: none;
                                visibility: hidden;
                            }
                        }

                        @media screen and (max-width: 400px) {
                            .header a{
                                display: none;
                            }
                            .mobile-header {
                                display: block;
                            }
                        }

                        .footer {
                            display: flex;
                            flex-direction: row;
                            flex-wrap: nowrap;
                            align-items: center; 
                            justify-content: space-around;
                            width: 100%;
                            height: 50px;
                            background-color: #333;
                            color: #fff;
                            font-size: 20px;
                            font-weight: 200;
                        }


                        .footer-item,
                        .footer-item a{
                            text-decoration: none;
                            color: #fff;
                        }

                        .container {
                            margin: 0 auto;
                            width: 80%;
                        }


                        .title {
                            margin: 40px auto;
                            width: 100%;
                            text-align: center;
                            font-size: 28px;
                            font-weight: 700;
                        }

                        .main-title {
                            font-size: 30px;
                        }

                        .sub-title {
                            font-size: 32px;
                        }

                        .description {
                            margin: 0 auto;
                            width: 80%;
                            font-size: 20px;
                        }
                        
                        .main {
                            display: flex;
                            flex-direction: column;     
                            align-items: center;      
                            margin: 40px auto;
                            text-align: center;
                            height: 300px;
                        }

                        .flow{
                            display: flex;
                            flex-direction: row;   
                            justify-content: space-evenly;
                            margin-bottom: 50px;
                            width: 90%;
                            height: 200px;
                        }

                        .buttom {
                            width: 270px;
                            height: 80px;
                            line-height: 80px;
                            background-color: #46bc79;
                            text-align: center;
                            border-radius: 40px;
                            margin-bottom: 50px;
                        }

                        .buttom a {
                            text-decoration: none;
                            color: #fff;
                            font-size: 20px;
                            font-weight: 600;
                        }

                        @media screen and (max-width: 700px) {
                            .flow{
                                margin-bottom: 50px;
                                flex-direction: column;   
                                align-items: center;    
                            }
                            .footer {
                                margin-top: 150px;
                            }
                        }
                    </style>
                </head>


                <body>

                    <div class='header'>
                        <a href='https://thingspeak.com/'>ThingSpeak</a>
                        <a href='https://www.generationrobots.com/media/adafruit-feather-huzzah-esp8266-user-guide-tutorial.pdf'>ESP8266</a>
                        <a href='https://www.dfrobot.com/product-2065.html'>CCS811 Air Quality</a>
                    </div>

                    <div class='mobile-header' id='mobile-icon'>
                        <span class='mobile-icon'></span>
                        <span class='mobile-icon'></span>
                        <span class='mobile-icon'></span>
                    </div>

                    <div class='mobile-left' id='mobile-panel'>
                        <div class='mobile-flow'>
                            <a href='https://thingspeak.com/'>ThingSpeak</a>
                        </div>
                        <div class='mobile-flow'>
                            <a href='https://www.generationrobots.com/media/adafruit-feather-huzzah-esp8266-user-guide-tutorial.pdf'>ESP8266</a>
                        </div>
                        <div class='mobile-flow'>
                            <a href='https://www.dfrobot.com/product-2065.html'>CCS811 Air Quality</a>
                        </div>
                    </div>
                    


                    <div class='container'>
                        <div class='title'>
                            <p class='main-title'>ESP8266 + CCS811 Air Quality + ThingSpeak</p>
                            <p class='sub-title'>Web Server </p>
                        </div>

                        <div class='description'>
                            This website is built with <strong>ESP8266 + CS811 Air Quality</strong> , you can use ESP8266 and CCS811 Air Quality to
                            measure data and send it to ThingSpeak website:
                            <a href='https://thingspeak.com/channels/1991175'>Here.</a>
                        </div>


                        <div class='main'>
                            <div class='flow'>
                                <div class='buttom'>
                                        <a href='1'>
                                        <div>GET RSSI</div>
                                    </a></div>
                                <div class='buttom'>
                                        <a href='2'>
                                        <div>GET Clear Air baselines numbers</div>
                                    </a></div>
                            </div>
                            <div class='flow'>
                                <div class='buttom'>
                                        <a href='3'>
                                        <div>GET CO2(ppm)</div>
                                    </a></div>
                                <div class='buttom'>
                                        <a href='4'>
                                        <div>GET TVOC(ppb)</div>
                                    </a></div>
                            </div>
                        </div>

                    </div>

                    <div class='footer'>
                        <div class='footer-item'>Autors:
                            <a href='https://github.com/junjielyu13'>@Junjie Li,</a>
                        </div>
                        <div class='footer-item'>©2022 Xarxa, UB.</div>
                    </div>


                    <script>
                        window.onload = function(){
                            var mobileIcon = document.querySelector('#mobile-icon');
                            var mobilePanel = document.querySelector('.mobile-left');

                            mobileIcon.onclick = function() {
                                if (mobilePanel.style.display === 'none') {
                                    mobilePanel.style.display = 'block';
                                } else {
                                    mobilePanel.style.display = 'none';
                                }
                            }

                            }
                    </script>


                </body>

                </html>
                ")
}