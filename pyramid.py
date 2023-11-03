import time

import pyautogui


def draw_pyramid(height):


if __name__ == "__main__":
    try:
        height = int(input("Enter the height of the pyramid: "))
        if height < 1:
            print("Height must be at least 1.")
        else:

            draw_pyramid(height)

    except ValueError:
        print("Please enter a valid number.")
