import json
import requests
from requests.exceptions import RequestException
import re
import time


def get_one_page(url):
    headers = {
        'User-Agent': 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)',
        'Cookie':'__mta=251016121.1705284786918.1705284877637.1705284901675.4; uuid_n_v=v1; uuid=9E7AEF80B34B11EE9BB767378F83FFD5AED86B823FC1444AA0D81A4DA5B27E72; _csrf=03ffe741b62e751e0e19510fff63a9e056fa80c0b9b84cc019bb88156a631667; _lxsdk_cuid=18d0ae4d846c8-00a16d2ba9d12c8-b7e2537-1fa400-18d0ae4d846c8; _lxsdk_s=18d0ae4d846-94b-161-30b%7C%7C14; _lxsdk=9E7AEF80B34B11EE9BB767378F83FFD5AED86B823FC1444AA0D81A4DA5B27E72; Hm_lvt_703e94591e87be68cc8da0da7cbd0be2=1705284787; Hm_lpvt_703e94591e87be68cc8da0da7cbd0be2=1705284902; WEBDFPID=64vzxwxx2y9z54181w2937250vw0u45z81w9zv4zy5x97958051z95x6-2020644840295-1705284839309GWAAGOK2960edaad10e294fa6f28397fe2285901593; token=AgF3JCZH00jMB9lvmcltA6n9tvfv4M41b_ZuhcFfnVfysgujLyACvgho3576cS792z2Sc6AG5dfNMQAAAABjHQAAJtKeaQNDwNHDg2eyUTroz4nVOtNzRZmDnPZmEIq1sEd713RWe4ldlha2Kc2rO6Ll; uid=3281096926; uid.sig=5NwMBJ39U9LoJzuPYGgAlemZ61w'
    }
    try:
        response = requests.get(url,headers=headers)
        if response.status_code == 200:
            return response.text
        return None
    except RequestException:
        return None


def parse_one_page(html):
    pattern = re.compile('<dd>.*?board-index.*?>(\d+)</i>.*?data-src="(.*?)".*?name"><a'
                         + '.*?>(.*?)</a>.*?star">(.*?)</p>.*?releasetime">(.*?)</p>'
                         + '.*?integer">(.*?)</i>.*?fraction">(.*?)</i>.*?</dd>', re.S)
    items = re.findall(pattern, html)
    for item in items:
        yield {
            'index': item[0],
            'image': item[1],
            'title': item[2],
            'actor': item[3].strip()[3:],
            'time': item[4].strip()[5:],
            'score': item[5] + item[6]
        }


def write_to_file(content):
    with open('result.txt', 'a', encoding='utf-8') as f:
        f.write(json.dumps(content, ensure_ascii=False) + '\n')


def main(offset):
    url = 'http://maoyan.com/board/4?offset=' + str(offset)
    html = get_one_page(url)
    for item in parse_one_page(html):
        print(item)
        write_to_file(item)


if __name__ == '__main__':
    for i in range(10):
        main(offset=i * 10)
        time.sleep(1)
