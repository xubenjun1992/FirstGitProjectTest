bsub -b -I -q q_sw_expr -N 16 -np 4 -cgsp 1 -host_stack 256 -share_size 6000 ./QVM
