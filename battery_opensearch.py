import os
import pandas as pd
import re
import boto3
import glob

def process_file(file_path):
    with open(file_path, 'rb') as file:
        file_bytes = file.read()
    processed_bytes = bytearray(b ^ 0x66 for b in file_bytes)
    try:
        result_string = processed_bytes.decode('utf-8')
    except UnicodeDecodeError:
        result_string = "Decoding Error: The processed bytes could not be decoded as UTF-8"
    return result_string