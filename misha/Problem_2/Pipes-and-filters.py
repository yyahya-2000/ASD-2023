def generate_all_board_configs():
    n = 8  # The size of the chessboard
    configs = []  # List to store all possible board configurations

    def generate_board_config(board, row):
        if row == n:
            configs.append(list(board))
            return
        for col in range(n):
            if is_safe(board, row, col):
                board[row] = col
                generate_board_config(board, row + 1)

    generate_board_config([None] * n, 0)
    return configs


def is_safe(board, row, col):
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def filter_valid_configs(configs):
    return [config for config in configs if is_valid_config(config)]


def is_valid_config(config):
    # Check if there are 8 queens on the board and none of them attack each other
    return len(config) == 8 and all(is_safe(config, i, config[i]) for i in range(8))


def display_board_configs(configs):
    for i, config in enumerate(configs, start=1):
        print(f"Solution {i}:")
        for row in range(8):
            line = ""
            for col in range(8):
                line += "Q" if config[row] == col else "."
            print(line)
        print()


if __name__ == "__main__":
    all_configs = generate_all_board_configs()
    valid_configs = filter_valid_configs(all_configs)
    display_board_configs(valid_configs)
