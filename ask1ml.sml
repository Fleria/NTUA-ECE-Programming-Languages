type 'a graph = { nodes : 'a list; edges : ('a * 'a * int) list }

let split v tvs es = List.partition (fun (x,y,_) -> (List.mem x tvs && y = v) || (List.mem y tvs && x = v)) es

let compare_weight (x1,y1,w1) (x2,y2,w2) = compare w1 w2

let min_weight l = List.fold_left (fun min x -> if compare_weight x min < 0 then x else min) (List.hd l) (List.tl l)

let add_edge e = function
  | [] -> [[e]]
  | es -> List.rev_map (fun x -> e::x) es

let s_tree g =
  let rec collect acc tvs es = function
    | [] -> acc
    | v::tl -> (*xorizei ti lista me ta nodes*) (*v einai to proto stoixeio tis listas me ta nodes*)
      let ps,qs = split v tvs es in (*tvs einai i lista me ta nodes pou exoume idi episkefthei*)
      (*ps einai ta nodes pou theloume, auta pou den kanoun to grafo connected*)
      if ps = [] then [] (* graph is not connected *)
      else
	collect (add_edge (min_weight ps) acc) (v::tvs) qs tl
  in
  collect [] [List.hd g.nodes] g.edges (List.tl g.nodes)

   let process_file process filename =
      let ch = open_in filename in
      try while true do process(input_line ch) done
      with End_of_file -> close_in ch;


let = { nodes = ['a'; 'b'; 'c'; 'd'; 'e'; 'f'; 'g'; 'h'];
          edges = [('a', 'b', 5); ('a', 'd', 3); ('b', 'c', 2);
                   ('b', 'e', 4); ('c', 'e', 6); ('d', 'e', 7);
                   ('d', 'f', 4); ('d', 'g', 3); ('e', 'h', 5);
                   ('f', 'g', 4); ('g', 'h', 1)] };;
