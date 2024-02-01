import requests

r = requests.get("https://baidu.com/favicon.ico")
print(r.text)
print(r.content)