type a17 = ( string * string list ) list;;
let rec a12 a1 a6 =
  match a1 with
    [] -> a6
  |   dependency :: action :: tl -> begin
		                    match (List.mem_assoc action a6, List.mem_assoc dependency a6) with
			            | (true, true) -> a12 tl (( action , dependency :: (List.assoc action a6)) :: List.remove_assoc action a6)
			            | (true, false) -> a12 tl ((dependency, []) :: ( action , dependency :: (List.assoc action a6)) :: List.remove_assoc action a6)
			            | (false, true) -> a12 tl (( action , dependency :: []) :: a6)
			            | (false, false) -> a12 tl ((dependency, []) :: ( action , dependency :: []) :: a6)
		                  end;;
let rec a13 a6 a4=
  try
    match (List.hd a6, a4) with
    | ((a8, a9), s) -> if (List.length a9) = 0
		       then
			 a13 (List.tl a6) (a8 :: s)
		       else
			 a13 (List.tl a6) s
  with _ -> begin
      if (List.length a4) = 0 then begin print_string ("cycle\n"); failwith "Cycle"; end
      else List.nth (List.sort (fun a2 a3 -> compare a2 a3) a4) 0
    end;;
let rec a14 a4 a5 =
  match (List.tl a4) with
  | [] -> if (List.hd a4) = a5 then [] else List.hd a4 :: []
  | _ -> if (List.hd a4) = a5 then List.tl a4
	 else (List.hd a4) :: a14 (List.tl a4) a5
;;
let rec a15 a6 a7 =
  match List.tl a6 with
  | [] ->
     if (List.mem a7 (snd (List.hd a6))) then
       ((fst (List.hd a6)), a14 (snd (List.hd a6)) a7) :: []
     else
       List.hd a6 :: []
  | s ->
     if (List.mem a7 (snd (List.hd a6))) then begin
			                     let (a8, a9) = List.hd a6 in
			                     (a8, (a14 a9 a7)) :: a15 (List.tl a6) a7;
			                   end
     else
       (List.hd a6) :: a15 (List.tl a6) a7
;;
let rec a16 a10 a11 =
  match (List.tl a10) with
  | [] -> if (fst (List.hd a10)) = a11 then (fst (List.hd a10), ["a";"a";"a";"a";"a";"a";"a";"a";"a"]) :: []
	  else (List.hd a10) :: []
  | s -> if (fst (List.hd a10)) = a11 then ((fst (List.hd a10)), ["a";"a";"a";"a";"a";"a";"a";"a";"a"]) :: (List.tl a10)
	 else (List.hd a10) :: a16 (List.tl a10) a11
;;
let rec topo_sort a6 a4 num =
  match num with
  | 0 -> a4
  | n -> begin
	 let vertex = a13 a6 [] in
	 let a10 = a16 a6 vertex in
	 topo_sort (a15 a10 vertex) (vertex :: a4) (num-1);
       end;;
let print_list a4 = List.iter (fun a2 -> print_string (a2 ^ "\n")) a4;;
let rec print_graph a6 = match a6 with
  | [] -> ()
  | (a2, a3) :: tl -> print_string ("A:" ^ a2 ^ "\n"); print_list a3; print_graph tl
;;
let a1 = ref [] in
    try
      while true do
	let line = (read_line ()) in
	a1 := line :: !a1;
      done
    with
    | _ -> begin
	   let a10 = a12 !a1 [] in
	   let sorted = topo_sort a10 [] (List.length a10) in
	   print_list (List.rev sorted);
         end
