# from selenium import webdriver
# from selenium.webdriver.chrome.options import Options

# chrome_options = Options()
# chrome_options.add_argument('--headless')
# chrome_options.add_argument('--disable-gpu')
# driver = webdriver.Chrome(options=chrome_options)
# driver.get("https://dreaife.icu/")
# print(driver.current_url)

import tesserocr
from PIL import Image

image = Image.open('G:/codeS/backOnGithub/Jupyter/spider/image.png')
print(tesserocr.image_to_text(image))