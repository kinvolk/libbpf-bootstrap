/* SPDX-License-Identifier: GPL-2.0-only */

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

struct file;

SEC("lsm/file_open")
int BPF_PROG(restrict_filesystems, struct file *file, int ret)
{
        bpf_printk("file opened\n");
        return 0;
}

char _license[] SEC("license") = "GPL";
