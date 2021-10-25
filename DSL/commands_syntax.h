//
// Created by ivanbrekman on 25.10.2021.
//

#define OK          return exit_codes::OK
#define EXIT        return exit_codes::EXIT
#define BREAK       return exit_codes::BREAK

#define PUSH(val)   push(&processor.stack, arg)
#define POP         pop(&processor.stack)
#define DUMP        stack_dump(processor.stack, "System dump call")

#define OUT         printf("%d\n", POP())
#define PRINT       print_stack(&processor.stack)

#define PUSH_C(val) push(&processor.call_stack, val)
#define POP_C       pop(&processor.call_stack)
#define IP          processor.ip
