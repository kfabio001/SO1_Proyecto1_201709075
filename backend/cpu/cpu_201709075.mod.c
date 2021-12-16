#include <linux/module.h>
//Header para usar KERN_INFO
#include <linux/kernel.h>

//Header para los macros module_init y module_exit
#include <linux/init.h>
//Header necesario porque se usara proc_fs
#include <linux/proc_fs.h>
/* for copy_from_user */
#include <asm/uaccess.h>	
/* Header para usar la lib seq_file y manejar el archivo en /proc*/
#include <linux/seq_file.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};
static struct proc_ops operaciones =
{
    .proc_open = al_abrir,
    .proc_read = seq_read
};


//Funcion a ejecuta al insertar el modulo en el kernel con insmod
static int _insert(void)
{
    proc_create("ejemplo_modulo", 0, NULL, &operaciones);
    printk(KERN_INFO "Mensaje al insertar modulo, Laboratorio SO 1\n");
    return 0;
}

//Funcion a ejecuta al remover el modulo del kernel con rmmod
static void _remove(void)
{
    remove_proc_entry("ejemplo_modulo", NULL);
    printk(KERN_INFO "Mensaje al remover modulo, Laboratorio SO 1\n");
}
#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xeeab4c1e, "module_layout" },
	{ 0xa3080447, "seq_read" },
	{ 0x240be803, "remove_proc_entry" },
	{ 0xc5850110, "printk" },
	{ 0xfe5d9eb7, "proc_create" },
	{ 0x6d289335, "init_task" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0xb32a092d, "seq_printf" },
	{ 0x72db9365, "single_open" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1DF3B402EBC7398686DDB44");
