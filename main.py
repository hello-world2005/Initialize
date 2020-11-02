import requests
import zipfile
import os
import sys


def Download(url):
    # qwq
    request = requests.get(url=url)
    with open(r"down.zip", "wb") as f:
        f.write(request.content)


def Unzip():
    zfile = zipfile.ZipFile('down.zip', 'r')
    for filename in zfile.namelist():
        data = zfile.read(filename)
        file = open(filename, 'w+b')
        file.write(data)
        file.close()


if __name__ == '__main__':
    # Download("")
    Unzip()
