import requests

r = requests.get("https://baidu.com/favicon.ico")
with open('favicon.ico', 'wb') as f:
    f.write(r.content)