class a19 (a1 : string) =
object(self)
  val mutable a2 = (a1 : string)
  val mutable a3 = ([] : a19 list)
  val mutable a4 = ("" : string)
  method a1 =
    a2
  method a21 =
    a3
  method a22 =
    a4
  method a23 (a5 : string) =
    a4 <- a5
  method a24 (a8 : a19) =
    a3 <- a3 @ [a8]
  method a25 =
    a4 <> "temp" && a4 <> "perm"
  method a26 =
    a4 = "temp"
end;;
class a6 =
object(self)
  val mutable a7 = ([] : a19 list)
  method a27 =
    a7
  method a28 (a8 : a19) =
    if (self#contains a8) = false then a7 <- a8 :: a7
  method a29 (a17 : a19) (a18 : a19) =
    let a9 = self#index_of a17 in
    let a10 = self#index_of a18 in
    let a11 = List.nth a7 a9 in
    let a12 = List.nth a7 a10 in
    a12#a24 a11
  method a30 (a13 : string list) =
    let rec a14 = (fun (a15 : string list) (a16 : int) ->
		   match a15 with
		   | [] ->
		      failwith "Cannot populate from an empty list"
		   | [line] ->
		      if a16 mod 2 = 0 then self#a28 (new a19 line)
		   | line :: tail ->
		      if a16 mod 2 = 0 then begin
					   let a17 = new a19 line in
					   let a18 = new a19 (List.hd tail) in
					   self#a28 a17;
					   self#a28 a18;
					   self#a29 a17 a18
					 end;
		      a14 tail (a16 + 1))
    in a14 a13 0
  method a22 (a8 : a19) (a5 : string) =
    let index = self#index_of a8 in
    (List.nth a7 index)#a23 a5;
  method index_of (a8 : a19) =
    let rec index_of_helper = (fun (verts : a19 list) (a16 : int) ->
			       match verts with
			       | [] ->
				  failwith "Cannot find index in an empty list"
			       | hd :: tl ->
				  if hd#a1 = a8#a1 then a16 else index_of_helper tl (a16 + 1))
    in index_of_helper a7 0
  method contains (a8 : a19) =
    let rec contains_helper = (function (verts : a19 list) ->
				        match verts with
					| [] ->
					   false
					| hd :: tl ->
					   if hd#a1 = a8#a1 then true else contains_helper tl)
    in contains_helper a7
end;;
let rec visit (g : a6) (node : a19) (output : string list ref) (flag : bool ref) =
  if node#a26 = true then flag := true;
  if node#a25 = true then begin
		         g#a22 node "temp";
		         let rec f = (function (adj : a19 list) ->
			                       match adj with
				               | [] ->
					          ()
				               | hd :: tl ->
					          visit g hd output flag;
					          f tl)
		         in f node#a21;
		            g#a22 node "perm";
		            output := node#a1 :: !output
	               end;;
let toposort (g : a6) =
  let flag = ref false in
  let source = ref (List.sort (fun a b -> compare b#a1 a#a1) g#a27) in
  let output = ref [] in
  let rec f = (fun (src : a19 list) (out : string list ref) ->
	       match src with
	       | [] ->
		  ()
	       | hd :: tl ->
		  visit g hd out flag;
		  f tl out)
  in f !source output;
     (!flag, !output);;
let a13 = ref [];;
  try
    while true do
      let line = read_line () in
      a13 := !a13 @ [line]
    done
  with
    End_of_file -> close_in stdin;;
  let g = new a6;;
    g#a30 !a13;;
    let sorted = toposort g in
        if fst(sorted) = false then List.iter print_endline (snd(sorted))
        else print_endline "cycle";;
