import sys

def exit_program():
    print("Exiting the program.")
    sys.exit(0)

def main():
    while True:
        user_input = input("Enter a command: ")
        if user_input.lower() in ("exit", "quit"):
            exit_program()
        else:
            # Process other commands
            # ...

         if __name__ == '__main__':
           main()
