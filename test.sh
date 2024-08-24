#!/bin/bash

make re
# ./push_swap 7 6 5
# ./push_swap "7 6 5"
# ./push_swap "7" "6" "5"
# ./push_swap "7" "6" "5" "4" "3" "2"
# ./push_swap "7" "6" "5" "-7"
# ./push_swap "7" "6" "5" "2" "-7"
# ./push_swap 42
# ./push_swap 3 2
# ./push_swap 0 1 2 3
# ./push_swap 0 1 2 3 4 5 6 7 8 9
# ./push_swap 9 8 7 6 5 4 3 2 1 0
# ./push_swap 35 52 67 91 86 863 59 34 18 212 6572 20 83
./push_swap 35 52 67 91 86 863 59 34 18 212 6572 20 83 6034 7835 8206 8688 7711 8628 8540 9293 2382 2042 1103 5601 8442 7549 6147 9734 5516 5772 2961 535 3992 8096 3618 9198 6094 2896 5260 8667 1809 2016 2763 1316 6748 6784 1375 7586 4175 8086 128 7895 5197 6382 5871 8597 1611 8629 761 1567 8080 6486 5392 3917 2162 5092 2977 7415 6954 3096 2772 6586 2373 7200 5724 6707 9396 7416 3944 3519 8722 136 107 7965 3743 2997 608 3739 8431 6696 8066 5064 239 8507 755 5006 9460 4447 7578 5094 8330 1909 8717 4529 8495 8369 8662 5962 7075 2036 6504 4524
# ./push_swap c c c
# ./push_swap 2 a 2
# ./push_swap "2" "a" "2"
# ./push_swap "b" "3" "2"
# ./push_swap "9" "6" "5 4"
# ./push_swap 'Between 0 and 9 randomly sorted values chosen>'

# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 7 6 5
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "7 6 5"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "7" "6" "5"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "7" "6" "5" "-7"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 42
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 0 1 2 3
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 0 1 2 3 4 5 6 7 8 9
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 9 8 7 6 5 4 3 2 1 0
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap c c c
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2 a 2
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "2" "a" "2"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "b" "3" "2"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap "9" "6" "5 4"
# valgrind --leak-check=full --show-leak-kinds=all ./push_swap 'Between 0 and 9 randomly sorted values chosen>'
