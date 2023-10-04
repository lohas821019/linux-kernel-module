#include <linux/module.h>
#include <linux/init.h>

//  Define the module metadata.
#define MODULE_NAME "greeter"
MODULE_AUTHOR("Jason Huang");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Jason make a simple kernel module to greet a user");
MODULE_VERSION("0.1.1");

//  Define the name parameter.
static char *name = "Jason";
module_param(name, charp, S_IRUGO);

// name 是参数的名称，是一个字符串。
// type 是参数的数据类型，例如 int、charp（字符指针）等。
// permissions 指定了参数的访问权限，通常使用宏 S_IRUGO、S_IWUSR 等来表示。

MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

static int __init greeter_init(void)
{
    pr_info("%s: module loaded at 0x%p\n", MODULE_NAME, greeter_init);
    pr_info("%s: greetings %s\n", MODULE_NAME, name);
    return 0;
}

static void __exit greeter_exit(void)
{
    pr_info("%s: goodbye %s\n", MODULE_NAME, name);
    pr_info("%s: module unloaded from 0x%p\n", MODULE_NAME, greeter_exit);
}

module_init(greeter_init);
module_exit(greeter_exit);
