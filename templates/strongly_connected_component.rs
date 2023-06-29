// Tarjan - O(V+E)

mod scc {
    struct St {
        scc_vec: Vec<Vec<usize>>,
        dfsn: Vec<Option<usize>>,
        stack: Vec<usize>,
        count: usize,
    }

    pub fn get_scc_vec(edge: &Vec<Vec<usize>>) -> Vec<Vec<usize>> {
        let n = edge.len();
        let mut st: St = St {
            scc_vec: Vec::new(),
            dfsn: vec![Some(0); n],
            stack: Vec::new(),
            count: 0,
        };

        for i in 0..n {
            if st.dfsn[i] == Some(0) {
                dfs(i, edge, &mut st);
            }
        }

        st.scc_vec
    }

    fn dfs(x: usize, edge: &Vec<Vec<usize>>, st: &mut St) -> usize {
        st.count += 1;
        st.dfsn[x] = Some(st.count);
        st.stack.push(x);

        let mut top: usize = st.count;
        for to in edge[x].iter() {
            if st.dfsn[*to] == Some(0) {
                top = std::cmp::min(top, dfs(*to, edge, st));
            } else if st.dfsn[*to] != None {
                top = std::cmp::min(top, st.dfsn[*to].unwrap());
            }
        }

        if top == st.dfsn[x].unwrap() {
            let mut now_scc: Vec<usize> = Vec::new();

            loop {
                let v = *(st.stack.last().unwrap());
                st.stack.pop();
                st.dfsn[v] = None;
                now_scc.push(v);
                if v == x {
                    break;
                }
            }

            st.scc_vec.push(now_scc);
        }

        top
    }
}
