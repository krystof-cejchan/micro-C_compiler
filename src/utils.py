def find_column(input, lexpos):
    last_cr = input.rfind("\n", 0, lexpos)
    return lexpos - last_cr
